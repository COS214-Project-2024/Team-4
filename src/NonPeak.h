#ifndef NONPEAK_H
#define NONPEAK_H

#include "TrafficFlow.h"

class NonPeak : public TrafficFlow {
    private:
        float trafficFlow = 0.2;
        char state = 'N';

    public:
        float getTrafficFlow();
        char getState();
    
};

#endif