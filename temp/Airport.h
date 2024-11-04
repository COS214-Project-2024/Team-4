#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transportation.h"

class Airport : public Transportation {
    public:
        std::string name;

    public:
        Airport(char state, std::string name, char type);
        float calculateCommute();
        std::string getAirportName();
};

#endif