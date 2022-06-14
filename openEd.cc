
#include "ed_application.srpc.h"
#include "workflow/WFFacilities.h"
#include"serviceMgr/serviceMgr.h"
using namespace srpc;

static WFFacilities::WaitGroup wait_group(1);
typedef unsigned int uint32;  

int main()
{
	struct WFGlobalSettings settings = GLOBAL_SETTINGS_DEFAULT;
    settings.endpoint_params.connect_timeout = 2 * 1000;
    settings.endpoint_params.response_timeout = -1;
    WORKFLOW_library_init(&settings);
	//查询ed_app地址，初始化客户端
	log_file = fopen("log_client.txt", "w");
	std::string ed_app_address = getSelectedServer("Electrical_Detector_metaApp");
    std::string ed_app_ip = getSelectedServerIP(ed_app_address);
	int ed_app_port = getSelectedServerPort(ed_app_address);
   	ElectricalDetector::SRPCClient ed_app_client(ed_app_ip.c_str(), ed_app_port);
	Log(NOTICE,"The address of dsp_agent is %s\n",ed_app_address.c_str());

	Detector_Open_Request detector_open_interface_req;
	RPCSyncContext detector_Open_synctx;
    Detector_Open_Response detector_Open_Response;

	uint32 signal_number;//辐射源编号
	uint32 serial_number[3];//型号对应库
	std::string possible_models[3]; //候选型号名称
	float confidence[3];//对应置信度（0~1），精度0.001
	float longitude;//经度  度
	float latitude;//纬度 度
	detector_open_interface_req.set_rf_freq_min(960);
	detector_open_interface_req.set_rf_freq_max(1280);
	ed_app_client.Detector_Open_Interface(&detector_open_interface_req, &detector_Open_Response,&detector_Open_synctx);
	Log(NOTICE,"The process is slow and the time is about 40 s, please wait a minute...");
	if(detector_Open_synctx.success){
			printf("open()成功\n");
            Log(NOTICE,"Syn invoke  function Detector_Open_Interface()...\n");
			printf("Syn invoke  function Detector_Open_Interface()...\n");
            signal_number = detector_Open_Response.signal_number();
            Log(NOTICE,"signal_number is %d",signal_number);
			printf("signal_number is %d",signal_number);
            if(signal_number != 0){
                for(int i=0; i<3; i++){
                  serial_number[i] = detector_Open_Response.serial_number(i);
                  possible_models[i] = detector_Open_Response.possible_models(i);
                  confidence[i] = detector_Open_Response.confidence(i);
                  Log(NOTICE,"Serial_number: %d,possible_models: %s, confidence: %f",serial_number[i], possible_models[i].c_str(), confidence[i]);
				  printf("Serial_number: %d,possible_models: %s, confidence: %f",serial_number[i], possible_models[i].c_str(), confidence[i]);
                }
				longitude = detector_Open_Response.longitude();
            	latitude = detector_Open_Response.latitude();
				Log(NOTICE,"longitude: %f,latitude: %f",longitude, latitude);
				printf("longitude: %f,latitude: %f",longitude, latitude);
            }
        } else{
            Log(ERROR,"Syn invoked  function Detector_Open_Interface() failed...\n");
        }   
        Log(NOTICE,"function Detector_Open_Interface() is invoked over!\n");

	printf("ed_app启动结束,按回车退出\n");
    getchar(); // press "Enter" to end.
	return 0;
}

