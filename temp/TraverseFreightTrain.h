#ifndef TRAVERSEFREIGHTTRAIN_H
#define TRAVERSEFREIGHTTRAIN_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "FreightTrain.h"

class Transportation;
class Highway;
class InsideRoad;
class Bus;
class Taxi;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;

class TraverseFreightTrain: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraverseFreightTrain(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif