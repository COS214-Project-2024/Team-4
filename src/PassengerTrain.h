#ifndef PASSANGERTRAIN_H
#define PASSANGERTRAIN_H

#include "Train.h"
#include "InsideRoad.h"

class PassengerTrain : public Train {
    private:
        std::vector<InsideRoad*> insideRoads;
        std::vector<PassengerTrain*> passengerTrains;          
    

    public:
        PassengerTrain(char state, std::string line);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addPassengerTrain(PassengerTrain *passengerTrain);
        InsideRoad *getInsideRoad(std::size_t x);
        PassengerTrain *getPassengerTrain(std::size_t x);
        std::string getTrainLine();
};

#endif