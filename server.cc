
#include <stdio.h>
#include <signal.h>
#include <iostream>
#include "dsp.srpc.h"
#include "Electrical_Detection_Service.srpc.h"
#include "ed_application.srpc.h"
#include "serviceMgr/serviceMgr.h"
#include <sys/types.h> //设置地址复用
#include <sys/socket.h>

//该版本在server1基础上将电侦流程更改流式处理，每次数据都会被转发至arm上面的服务，通过服务返回的isResult标志位判断本次结果是否是一次完整处理。
using namespace srpc;
typedef unsigned int uint32;
#define MAXLINE 30000
int volatile listenfd;
int volatile connfd;
pthread_mutex_t global_mutex = PTHREAD_MUTEX_INITIALIZER;
int volatile running = 1;
float RF_Freq_min;
float RF_Freq_max;
//ed_app返回值
uint32  signal_number;//辐射源编号
uint32  serial_number[3];//型号对应库
std::string  possible_models[3]; //候选型号名称
float  confidence[3];//对应置信度（0~1），精度0.001
float  longitude;//经度  度
float  latitude;//纬度 度

class ElectricalDetectorServiceImpl : public ElectricalDetector::Service
{
  static void * open_handler(void *){
       //同步调用fpga_agent()和dsp_agent();
        std::string dsp_address = getSelectedServer("DSP_agent");
        std::string dsp_ip = getSelectedServerIP(dsp_address);
        int dsp_port = getSelectedServerPort(dsp_address);
        DSPController::SRPCClient dsp_client(dsp_ip.c_str(), dsp_port);
        Log(NOTICE,"The address of dsp_agent is %s\n",dsp_address.c_str());
        DSPControllerRequest dsp_req;
        DSPControllerResponse dSPControllerResponse;
        // 1.同步load电侦
        printf("Asyn invoked  function LoadElecReco()\n");
        Log(NOTICE,"Asyn invoked  function LoadElecReco()\n");
        RPCSyncContext loadElecReco_synctx;
        dsp_client.LoadElecReco(&dsp_req,&dSPControllerResponse,&loadElecReco_synctx);
        if(loadElecReco_synctx.success){
            printf("Syn invoked function LoadElecReco() ok\n");
            Log(NOTICE,"Syn invoked function LoadElecReco() ok\n");
        }else{
            printf("Syn invoked function LoadElecReco() failed......\n");
            Log(NOTICE,"Syn invoked function LoadElecReco() failed......\n");
        }

        // 2.睡几秒
        Log(NOTICE, "Now is waiting for the electrical detector loading, the time is about 30 s, please wait a minute...\n");
        printf( "Now is waiting for the electrical detector loading, the time is about 30 s, please wait a minute...\n");
        sleep(30);
        printf("睡眠结束\n");
        // 3.同步start电侦
        Log(NOTICE, "Next will start electrical detector!\n");
        printf("Next will start electrical detector!\n");
        RPCSyncContext startElecReco_synctx;
        dsp_client.StartElecReco(&dsp_req,&dSPControllerResponse,&startElecReco_synctx);
        if(startElecReco_synctx.success){
          Log(NOTICE,"Syn invoked  function StartElecReco() over\n");
          printf("Syn invoked  function StartElecReco() over\n");
        }else{
          Log(NOTICE,"Syn invoked  function StartElecReco() failed.......\n");
          printf("Syn invoked  function StartElecReco() failed.......\n");
        }

        //4.socket_while() 等待朱工数据传输
        int  n;
        printf("======port %d is waiting for receiveDetection_report======\n",5300);
        Log(NOTICE,"Now is waiting for receiving Detection_report");
        char data[9000] = {0};
        //调用ed_service(),初始化client
        Log(NOTICE,"Next will invoke electrical detector service!");
        std::string ed_address = getSelectedServer("ElectricalDetector_metaservice");
        std::string ed_ip = getSelectedServerIP(ed_address);
        int ed_port = getSelectedServerPort(ed_address);
        Log(NOTICE,"The address of ElectricalDetector_metaservice is %s\n",ed_address.c_str());
        // 电侦client去调用西电电侦服务
        Electrical_Detecion_service::SRPCClient ed_client(ed_ip.c_str(),ed_port);
        
        // 接受朱总数据去构造调用电侦服务的请求参数
        while(true){
            if( (connfd = accept(listenfd, (struct sockaddr*)NULL, NULL)) == -1){
                Log(ERROR,"accept socket error: %s(errno: %d)",strerror(errno),errno);
            }
            printf("connected to client...\n");
            Log(NOTICE,"connected to client...\n");
            int dataSum = 0;
            //每次连接等收够8478个数据，再调用下面程序。
            while( dataSum<8478){
                n = recv(connfd, data, MAXLINE, 0);//recvAPI可以获取规定字符长度sockfd的内容到指定buffer
                dataSum += n;
                if(dataSum >8478){
                  printf("本次收到的总数据量大于8478,数据量是:%d\n",dataSum);
                  break;
                }
            }
            printf("Received data from client, the size is %d\n", n);
            Log(NOTICE,"Received data from client, the size is %d\n", n);
                       
            if(dataSum != 8478){
                printf("本次数据接收异常，断开连接,数据量是：%d\n",dataSum);
            }else{
                data[dataSum] = '\0';//添加文件结束符   
                printf("本次数据接收正常，开始调用服务,数据量是：%d\n",dataSum); 
                //5.同步调用目标识别方法
                //构造参数
                Log(NOTICE,"Syn invoke function target_recognition()\n");
                RPCSyncContext target_Recognition_synctx;
                Target_Recognition_Request target_Recognition_Request;
                Target_Recognition_Response target_Recognition_Response;
                Log(NOTICE,"RF_Freq_min is %f",RF_Freq_min);
                Log(NOTICE,"RF_Freq_max is %f",RF_Freq_max);
                for(int i=0; i<20; i++){
                  Log(NOTICE,"%x",data[i]);
                }       
                printf("send data size is %d\n", dataSum);
                Log(NOTICE,"send data size is %d\n", dataSum);
                // data数据接受朱总
                target_Recognition_Request.set_data(data,8478);
                target_Recognition_Request.set_rf_freq_min(RF_Freq_min);
                target_Recognition_Request.set_rf_freq_max(RF_Freq_max);
                target_Recognition_Request.set_datasize(8478);
                printf("开始调用目标识别\n");  
                ed_client.target_recognition(&target_Recognition_Request, &target_Recognition_Response, &target_Recognition_synctx);
                if(target_Recognition_synctx.success){
                    printf("目标识别调用成功\n");
                }else{
                    Log(ERROR,"Syn invoked  function target_recognition() failed...\n");
                    printf("目标识别调用失败\n");
                }   
                Log(NOTICE,"function target_recognition() is invoked over!\n");
                  

                  //6.同步调用目标定位方法
                  Target_Location_Request target_Location_Request;
                  RPCSyncContext target_Location_synctx;
                  Target_Location_Response target_Location_Response;
                  target_Location_Request.set_data(data,8478);
                  target_Location_Request.set_rf_freq_min(RF_Freq_min);
                  target_Location_Request.set_rf_freq_max(RF_Freq_max);
                  target_Location_Request.set_datasize(8478);
                  //同步调用目标定位
                  Log(NOTICE,"Syn invoke function target_location()");
                  printf("开始调用目标定位方法\n");
                  ed_client.target_location(&target_Location_Request, &target_Location_Response, &target_Location_synctx);
                  if (target_Location_synctx.success){
                      printf("目标定位调用成功\n");
                      // longitude = target_Location_Response.longitude();
                      // latitude = target_Location_Response.latitude();
                      // Log(NOTICE,"longitude: %f,latitude: %f",longitude, latitude);
                    }else{
                      Log(ERROR,"Syn invoke function target_location() failed ...");
                    }
                  //判断是否是可返回的结果
                  if(target_Recognition_Response.isresult() == 1){
                      printf("一次完整过程完成，返回给规划模块\n");
                      printf("\n\n");
                      //7.几个操作调用完毕，统一返回数据
                      //辐射源编号
                      int serial_number_size = target_Recognition_Response.serial_number().size();
                      int possible_models_size = target_Recognition_Response.possible_models().size();
                      int confidence_size = target_Recognition_Response.confidence().size();
                      printf("3 size is %d, %d, %d", serial_number_size, possible_models_size, confidence_size);
                      signal_number = target_Recognition_Response.signal_number();
                    
                      for (int i = 0; i < serial_number_size; i++)
                      {
                        serial_number[i] = target_Recognition_Response.serial_number(i);
                        possible_models[i] = target_Recognition_Response.possible_models(i);
                        confidence[i] = target_Recognition_Response.confidence(i);
                        printf("Serial_number: %d,possible_models: %s, confidence: %f", serial_number[i], possible_models[i].c_str(), confidence[i]);
                      }
                      longitude = target_Location_Response.longitude();
                      latitude = target_Location_Response.latitude();
                      printf("Ressult is returned to client\n"); 
                      Log(NOTICE,"Ressult is returned to client\n");
                  }           
                printf("一次完整过程完成,close connfd\n");
              }
              close(connfd); 
              printf("本次连接已关闭\n");
          }//while true
      } 
  

  void Detector_Open_Interface(Detector_Open_Request *request, Detector_Open_Response *response, srpc::RPCContext *ctx) override{
		    Log(NOTICE,"received request for function Detector_Open_Interface() \n");
        printf("enter open() \n");
        pthread_mutex_lock(&global_mutex);//数据上锁
        running = 1;
        pthread_mutex_unlock(&global_mutex);//数据解锁
        RF_Freq_min = request->rf_freq_min();
        RF_Freq_max = request->rf_freq_max();
        int * thread_res = NULL;
		    pthread_t th;
        int ret = pthread_create(&th, NULL, open_handler,NULL);
        while(running){
            //正在接收数据中
        }
        //停止接收数据
        printf("running为0, 停止接收数据,杀死接收线程\n");
        close(connfd);
        printf("close connfd :%d\n", connfd);
        int kill_res = pthread_kill(th,0);
        if(kill_res == ESRCH)
        {   
            printf("new thread tid is not found.\n");
            printf("ret_kill = %d\n",kill_res);
        }  
        printf("Kill thread res is: %d\n",kill_res);
        response->set_signal_number(signal_number);
        for(int i=0; i<3; i++){
          //型号对应库
          //候选型号名称
          //对应置信度（0~1），精度0.001
          response->add_serial_number(serial_number[i]);
          response->add_possible_models(possible_models[i]);
          response->add_confidence(confidence[i]);
        }       
          //经度  度 
          response->set_longitude(longitude);
          //纬度 度 
          response->set_latitude(latitude);  
          printf("leave open()\n\n\n\n");            
	}
  void Detector_Close_Interface(Detector_Close_Request *request, Detector_Close_Response *response, srpc::RPCContext *ctx) override
  {     
      //设置超时时间为无限
      struct WFGlobalSettings settings = GLOBAL_SETTINGS_DEFAULT;
      settings.endpoint_params.connect_timeout = 2 * 1000;
      settings.endpoint_params.response_timeout = -1;
      WORKFLOW_library_init(&settings);
      printf("received request for function Detector_Close_Interface() \n");
      Log(NOTICE, "received request for function Detector_Close_Interface() \n");
      printf("running 置为0\n");
      pthread_mutex_lock(&global_mutex);//数据上锁
      running = 0;
      pthread_mutex_unlock(&global_mutex);//数据解锁
      close(connfd);
      printf("close connfd :%d\n", connfd);
      //异步调用fpga_agent()和dsp_agent();
      std::string dsp_address = getSelectedServer("DSP_agent");
      std::string dsp_ip = getSelectedServerIP(dsp_address);
      int dsp_port = getSelectedServerPort(dsp_address);
      DSPController::SRPCClient dsp_client(dsp_ip.c_str(), dsp_port);
      Log(NOTICE, "The address of dsp_agent is %s\n", dsp_address.c_str());
      DSPControllerRequest dsp_req;
      DSPControllerResponse dSPControllerResponse;
      // stop电侦（这里是同步调用）
      Log(NOTICE, "syn invoked  function StopElecReco()\n");
      printf("syn invoked  function StopElecReco()\n");
      RPCSyncContext  stopElecReco_ctx;

      dsp_client.StopElecReco(&dsp_req,&dSPControllerResponse,&stopElecReco_ctx);
      if(stopElecReco_ctx.success){
        Log(NOTICE,"function StopElecReco() is invoked over\n");
        printf("function StopElecReco() is invoked over\n");
      }else{
        Log(NOTICE,"function StopElecReco() is invoked over\n");
        printf("function StopElecReco()is invoked over\n");
      }
    
      Log(NOTICE, "停止接收数据\n");
      Log(NOTICE, "function Detector_Close_Interface() is invoked over\n");
      
      printf("function Detector_Close_Interface() is invoked over\n");
      printf("\n\n");
  }
  


  void get_reconstruct_time(ED_ReconstructTime_Request *request, ED_ReconstructTime_Response *response, srpc::RPCContext *ctx) override
  {
      //设置超时时间为无限
    struct WFGlobalSettings settings = GLOBAL_SETTINGS_DEFAULT;
    settings.endpoint_params.connect_timeout = 2 * 1000;
    settings.endpoint_params.response_timeout = -1;
    WORKFLOW_library_init(&settings);
    printf("received request for function get_reconstruct_time() ");
    Log(NOTICE, "received request for function get_reconstruct_time() ");
    //异步调用fpga_agent()和dsp_agent();
    std::string dsp_address = getSelectedServer("DSP_agent");
    std::string dsp_ip = getSelectedServerIP(dsp_address);
    int dsp_port = getSelectedServerPort(dsp_address);
    DSPController::SRPCClient dsp_client(dsp_ip.c_str(), dsp_port);
    Log(NOTICE, "The address of dsp_agent is %s\n", dsp_address.c_str());
    DSPControllerRequest dsp_req;
    ReconstructTimeResponse reconstructTimeResponse;
    RPCSyncContext reconstructTimeCtx;

    //获得重构时间
    Log(NOTICE, "调用dsp_agent查询重构时间\n");
    printf( "调用dsp_agent查询重构时间\n");
    float time=0.0;
    do{
        dsp_client.GetElecReconstructTime(&dsp_req, &reconstructTimeResponse, &reconstructTimeCtx);
        if (reconstructTimeCtx.success)
        {
          time = reconstructTimeResponse.time();
        }
        else
        {
          printf("Syn invoke function GetElecReconstructTime() failed ...\n");
          break;
        }   
    }while(time==0.0);
    printf("返回重构时间%f\n",time);
    response->set_timelen(time);
  }

};

void sig_handler(int signo) { }

int main(int argc, char *argv[])
{
  log_file = fopen("log.txt", "w");
  //接收参数，当前宿主机ip,服务权重
  if (argc != 3)
  {
    Log(ERROR, "You should use 2 arguments, the service stop...\n");
  }

  string serviceIP = argv[1];
  string checkURL = serviceIP + ":5205";
  int weight = atoi(argv[2]);
  string serviceName = "Electrical_Detector_metaApp";
  // string serviceId = "id";软件框架会生成随机数
  int servicePort = 5105;
  string serviceAddress = serviceIP + ":" + to_string(servicePort);
  string serviceProtocol = "srpc";
  string serviceVersion = "v1.0";
  string serviceProvider = "hanxi";
  
  int checkType = TCP_CHECK;
  string interval = "5s";
  string timeout = "3s";
  string checkDeregisterCriticalServiceAfter = "10s";

  ServiceInfo *serviceInfo = new ServiceInfo(serviceName, "", serviceIP, servicePort, serviceProtocol, serviceVersion, serviceProvider,
                                             weight, checkType, checkURL, interval, checkDeregisterCriticalServiceAfter, timeout);

  int regRes = registerService(serviceInfo);
  if (regRes != 0)
  {
    Log(ERROR, "Register service failed, the service stop...\n");
    return 0;
  }
  signal(SIGINT, sig_handler);
  signal(SIGTERM, sig_handler);
  SRPCServer server_tcp;
  ElectricalDetectorServiceImpl electricalDetectorServiceImpl;
  server_tcp.add_service(&electricalDetectorServiceImpl);
  Log(NOTICE, "The address of current host is %s\n", serviceAddress.c_str());
  server_tcp.start(servicePort);
  
  // 开启套接字，主要接受朱总中转的数据（电侦的辐射源识别报告）
  struct sockaddr_in  servaddr;
  if( (listenfd = socket(AF_INET, SOCK_STREAM, 0)) == -1 ){
      printf("receiveDetection_report(): create socket error: %s(errno: %d)\n",strerror(errno),errno);
  }
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET; 
  servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  //servaddr.sin_addr.s_addr =inet_addr("10.119.84.88");//限定只接受本地连接请求
  servaddr.sin_port = htons(5300);

  //这里是设置地址复用，解决程序异常结束后再次执行时导致的端口被占用问题
  int on = 1;
  printf(" connfd :%d\n", connfd);
  printf(" listenfd :%d\n", listenfd);
  setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

  if( bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1){
      printf("bind socket error: %s(errno: %d)\n",strerror(errno),errno);
  }
  if( listen(listenfd, 10) == -1){
      printf("listen socket error: %s(errno: %d)\n",strerror(errno),errno);
  }
  printf("等待连接中\n");
  getchar(); // press "Enter" to end.
  close(listenfd);
  printf("电侦应用已启动,按enter退出\n");
  getchar(); // press "Enter" to end.
  return 0;
}
