#ifndef TRAVERSESTATE_H
#define TRAVERSESTATE_H

#include <vector>

#include "Transportation.h"
// #include "Building.h"

class Transportation;
// class Building;

class TraverseState {
    private:
        Transportation *layer;

    public:
        TraverseState(Transportation *element);
        virtual bool nextList() = 0;
        virtual bool prevList() = 0;
        virtual Transportation* getPos(size_t x) = 0;
        Transportation* getLayer();
        // virtual std::vector<Building*> getBuildings() = 0;

};

#endif