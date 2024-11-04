#ifndef TRAVERSEBUS_H
#define TRAVERSEBUS_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "ComercialAirport.h"
#include "PassengerTrain.h"

class Transportation;
class InsideRoad;
class Bus;
class ComercialAirport;
class PassengerTrain;

class TraverseBus: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 3;

    public:
        TraverseBus(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif