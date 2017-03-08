#include "gettime.h"
#include <chrono>
#include <ctime>
#include <stdlib.h>

using namespace std::chrono;


long long int getTime(){

        milliseconds ms = duration_cast< milliseconds >(system_clock::now().time_since_epoch());

        return ms.count();
        }

