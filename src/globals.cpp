#include "globals.h"

int AoS;		//Amount of sensors parsed from config.cfg
int globalid;		//For requesting from correct sensor with MQTT
int rflag = 0;		//requestflag
float gvalue = 0;	//global value holder
int mqttcounter = 0;	//For tracking failed MQTT request-responses
int wapicecounter = 0;	//for tracking failed Wapice send-fails
int testmode = 0;	//For handling test mode console prints

//Wapice specific strings
std::string wapiceDevID = "";
std::string wapiceUser = "";
std::string wapicePassword = "";
std::string wapiceUrl = "";

//Vector arrays for configuration
std::vector< std::vector <long long int> > timerArray;
std::vector <std::vector <int> > busArray;
std::vector <std::vector <std::string> > attrArray;
std::vector <std::vector <float> > modArray;
std::vector <std::thread> threads;
