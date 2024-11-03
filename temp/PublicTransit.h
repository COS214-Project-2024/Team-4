#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include <iostream>

#include "Transportation.h"

class PublicTransit : public Transportation {
    private:
        std::string route;

    public:
        PublicTransit(char state, std::string route);
        float calculateCommute();
        std::string getRoute();
};

#endif