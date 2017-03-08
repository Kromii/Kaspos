#include "dataloop.h"



void dataLoop(int id){

	if (busArray[id][2] == 3){	//Used for MQTT, senddata is called at on_message callback - See mqtt.cpp
		readData(id);
	}
	else{
		float _value = readData(id);
		std::thread t2 (senddatathread, id, _value); //Practically anything else.
		t2.detach();
	}
	return;
}
