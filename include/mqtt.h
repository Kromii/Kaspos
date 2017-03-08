#include "globals.h"
#include "senddata.h"
#include <stdexcept>
#include <algorithm>


void on_message(struct mosquitto, void *, const struct mosquitto_message *);

void mqttlistener();

void mqttsender();

