#include "senddata.h"


void senddatathread(int _id, float _value){

	//usleep(rand() %5000);
	if (attrArray[_id][5] == "Wapice" || attrArray[_id][5] == "wapice"){

		if (testmode == 1){
			std::cout << "Wapice send  " << _id << "value : " << _value << ", fails: " << wapicecounter << std::endl;
		}
		wapicecounter = wapicecounter + 1;
		wapiceSend(attrArray[_id][0], attrArray[_id][1], attrArray[_id][2], _value);
	}

	else if (attrArray[_id][5] == "Elisa" || attrArray[_id][5] == "elisa"){
	//Not implemented, placeholder
		if (testmode == 1){
			std::cout << "Elisa send" << std::endl;
		}
	}
	else if (attrArray[_id][5] == "Amazon" || attrArray[_id][5] == "amazon"){
	//Not implemented, placeholder
		if (testmode == 1){
			std::cout << "Amazon send" << std::endl;
		}
	}
	else{
		std::cout <<  "Server name isn't recognized, skipping senddata." << std::endl;
	}
}
