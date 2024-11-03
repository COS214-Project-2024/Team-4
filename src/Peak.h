#ifndef PEAK_H
#define PEAK_H

#include "TrafficFlow.h"

class Peak : public TrafficFlow {
    private:
        char state = 'P';
        float trafficFlow = 0.8;  

    public:
        float getTrafficFlow();
        char getState();
    
};

#endif