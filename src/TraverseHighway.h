#ifndef TRAVERSEHIGHWAY_H
#define TRAVERSEHIGHWAY_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"

class Transportation;
class Highway;
class InsideRoad;

class TraverseHighway: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraverseHighway(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif