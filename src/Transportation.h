#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <iostream>

#include "TrafficFlow.h"
#include "Peak.h"
#include "NonPeak.h"
#include "LunchRush.h"

class Transportation {
    private:
        TrafficFlow *state;
    public:
        Transportation(char state);
        float getTrafficFlow();
        bool setState(char state);
        virtual float calculateCommute() = 0;
        ~Transportation();
    

};

#endif