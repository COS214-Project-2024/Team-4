#ifndef TRAVERSECARGOAIRPORT_H
#define TRAVERSECARGOAIRPORT_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "CargoAirport.h"

class Transportation;
class InsideRoad;
class CargoAirport;

class TraverseCargoAirport: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraverseCargoAirport(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif