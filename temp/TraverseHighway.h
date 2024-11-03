#ifndef TRAVERSEHIGHWAY_h
#define TRAVERSEHIGHWAY_h

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "Highway.h"

class Transportation;
class Highway;

class TraverseHighway: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 1;

    public:
        TraverseHighway(Transportation *element);
        int getCurrentList();
        bool nextList();
        bool prevList();
        std::vector<Transportation*> getList();
        // std::vector<Building*> getBuildings()        

};

#endif