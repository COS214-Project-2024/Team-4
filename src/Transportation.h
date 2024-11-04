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
        char type;
    public:
        Transportation(char state, char type);
        float getTrafficFlow();
        bool setState(char state);
        char getType();
        // virtual float calculateCommute() = 0;
        ~Transportation();
    

};

#endif