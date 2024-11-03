#ifndef FREIGHTTRAIN_H
#define FREIGHTTRAIN_H

#include "Train.h"
#include "InsideRoad.h"

class InsideRoad;

class FreightTrain : public Train {
    private:
        float weight;
        float length;

        std::vector<InsideRoad*> insideRoads;   
        std::vector<FreightTrain*> freightTrains;   

    public:

        FreightTrain(char state, std::string line, float weight, float length);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addFreightTrain(FreightTrain *freightTrain);
        InsideRoad* getInsideRoad(size_t index);
        FreightTrain* getFreightTrain(size_t index);
        float getWeight();
        float getLength();
        std::string getTrainLine();
};

#endif