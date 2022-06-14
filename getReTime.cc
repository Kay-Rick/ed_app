
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
	printf("The address of dsp_agent is %s\n",ed_app_address.c_str());

	ED_ReconstructTime_Request eD_ReconstructTime_Request;
	RPCSyncContext eD_ReconstructTime_synctx;
    ED_ReconstructTime_Response eD_ReconstructTime_Response;

	ed_app_client.get_reconstruct_time(&eD_ReconstructTime_Request, &eD_ReconstructTime_Response,&eD_ReconstructTime_synctx);
	if(eD_ReconstructTime_synctx.success){
        printf("Syn invoked  function get_reconstruct_time()\n");
		float time = eD_ReconstructTime_Response.timelen();
		printf("重构时间是：%f\n",time);
	} else{
		printf("Syn invoked  function get_reconstruct_time() failed...\n");
	}   
	printf("function get_reconstruct_time() is invoked over!\n");

	printf("ed_app获取重构时间结束，按回车退出\n");
    getchar(); // press "Enter" to end.
	return 0;
}

