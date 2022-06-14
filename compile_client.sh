#!/bin/bash
g++ -o client client.cc ed_application.pb.cc Electrical_Detection_Service.pb.cc  dsp.pb.cc -L ../../x86_serviceMgr_staticlib -lserviceMgr --std=c++11 -lsrpc -ljsoncpp -lcurl

g++ -o stop_ed stop_ed.cc ed_application.pb.cc Electrical_Detection_Service.pb.cc  dsp.pb.cc -L ../arm_serviceMgr_staticlib -lserviceMgr --std=c++11 -lsrpc -ljsoncpp -lcurl
