#ifndef TRAVERSEINSIDEROAD_H
#define TRAVERSEINSIDEROAD_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
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

class TraverseInsideRoad: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 7;

    public:
        TraverseInsideRoad(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif