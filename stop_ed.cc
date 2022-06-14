
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
    settings.endpoint_params.response_timeout = 600 *1000;
    WORKFLOW_library_init(&settings);
	//查询ed_app地址，初始化客户端
	log_file = fopen("stop.txt", "w");
	std::string ed_app_address = getSelectedServer("Electrical_Detector_metaApp");
    std::string ed_app_ip = getSelectedServerIP(ed_app_address);
	int ed_app_port = getSelectedServerPort(ed_app_address);
   	ElectricalDetector::SRPCClient ed_app_client(ed_app_ip.c_str(), ed_app_port);
	Log(NOTICE,"The address of dsp_agent is %s\n",ed_app_address.c_str());
	
	Detector_Close_Request detector_Close_Request;
	RPCSyncContext detector_Close_synctx;
    Detector_Close_Response detector_Close_Response;

	ed_app_client.Detector_Close_Interface(&detector_Close_Request, &detector_Close_Response,&detector_Close_synctx);
	if(detector_Close_synctx.success){
        Log(NOTICE,"Syn invoked  function Detector_Close_Interface()\n");
	} else{
		Log(ERROR,"Syn invoked  function Detector_Close_Interface() failed...\n");
	}   
	Log(NOTICE,"function Detector_Close_Interface() is invoked over!\n");

	printf("ed_app调用结束，按回车退出\n");
    getchar(); // press "Enter" to end.
	return 0;
}
