#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <mosquitto.h>
#include <mosquittopp.h>
#include <stdio.h>
#include <cstdlib>
#include <errno.h>
#include <stdlib.h>
#include <modbus/modbus.h>
#include <sys/sysinfo.h>
#include <libconfig.h++>
#include <thread>
#include <mutex>
#include <IOT_API.h> 

#include "gettime.h"

extern int AoS;
extern int globalid;
extern int rflag;
extern int mqttcounter;
extern int wapicecounter;
extern int testmode;


extern std::string wapiceDevID;
extern std::string wapiceUser;
extern std::string wapicePassword;
extern std::string wapiceUrl;

extern std::vector< std::vector <long long int> > timerArray;
extern std::vector <std::vector <int> > busArray;
extern std::vector <std::vector <std::string> > attrArray;
extern std::vector <std::vector <float> > modArray;
