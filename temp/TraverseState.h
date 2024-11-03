#ifndef TRAVERSESTATE_h
#define TRAVERSESTATE_h

#include <vector>

#include "Transportation.h"
// #include "Building.h"

class Transportation;
// class Building;

class TraverseState {
    private:
        Transportation *Element;

    public:
        TraverseState(Transportation *element);
        virtual bool nextList() = 0;
        virtual bool prevList() = 0;
        virtual std::vector<Transportation*> getList() = 0;
        Transportation* getElement();
        // virtual std::vector<Building*> getBuildings() = 0;

};

#endif