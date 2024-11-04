#ifndef ROAD_H
#define ROAD_H

#include "Transportation.h"

class Road : public Transportation {
    private:
        std::string roadName;

    public:
        Road(char state, std::string roadName, char type);
        float calculateCommute();
        std::string getName();

    
};

#endif