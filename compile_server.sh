#!/bin/bash
g++ -o server server.cc ed_application.pb.cc Electrical_Detection_Service.pb.cc  dsp.pb.cc -L ../../x86_serviceMgr_staticlib -lserviceMgr --std=c++11 -lsrpc -ljsoncpp -lcurl
