#ifndef LUNCHRUSH_H
#define LUNCHRUSH_H

#include "TrafficFlow.h"

class LunchRush : public TrafficFlow{
    private:
        char state = 'L';
        float trafficFlow = 0.5;

    public:
        float getTrafficFlow();
        char getState();
};

#endif