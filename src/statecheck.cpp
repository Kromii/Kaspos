#include "statecheck.h"
#include "readdata.h"
#include "globals.h"

void stateCheck() {
		for (int id = 0; id < AoS; id++){
			if ((timerArray[id][1] + timerArray[id][0])  <= getTime()){
				timerArray[id][1] = getTime();
				globalid = id;
				dataLoop(id);
				usleep(50);
			}
		}
	return;
}



