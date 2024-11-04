#ifndef TRAVERSEPASSENGERTRAIN_H
#define TRAVERSEPASSENGERTRAIN_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "PassengerTrain.h"

class Transportation;
class InsideRoad;
class PassengerTrain;

class TraversePassengerTrain: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraversePassengerTrain(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif