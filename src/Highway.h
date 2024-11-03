#ifndef HIGHWAY_H
#define HIGHWAY_H

#include <vector>

#include "Road.h"
#include "InsideRoad.h"

class Highway : public Road {
    private:
        float speedLimit;
        std::vector<InsideRoad*> insideRoads;
        std::vector<Highway*> highways;

    public:
        Highway(char state, std::string roadName, float speedLimit);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addHighway(Highway *highway);
        InsideRoad *getInsideRoad(std::size_t x);
        Highway *getHighway(std::size_t x);
        std::string getRoadName();
        float getSpeedLimit();
    
};

#endif