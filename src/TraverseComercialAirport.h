#ifndef TRAVERSECOMERCIALAIRPORT_H
#define TRAVERSECOMERCIALAIRPORT_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"

class Transportation;
class InsideRoad;
class ComercialAirport;

class TraverseComercialAirport: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraverseComercialAirport(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif