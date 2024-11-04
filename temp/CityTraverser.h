//CONCRETE ITERATOR

#ifndef CITYTRAVERSER_h
#define CITYTRAVERSER_h

#include <vector>

#include "Traverser.h"
#include "Transportation.h"
// #include "Building.h"

class Transportation;
class Traverser;
// class Building;

class CityTraverser: public Traverser{
    private:
        int currentElement;
        Transportation* Element;
        std::vector<Transportation*> prevLayers;
        Transportation* currentLayer;

    public:
        CityTraverser();
        CityTraverser(Transportation* t);
        CityTraverser(CityTraverser* t);
        CityTraverser(std::vector<Transportation*> t);
        bool operator++();
        bool operator--();
        bool operator+();
        bool operator-();
        Transportation* operator*();
        Transportation* getCurrentLayer();
        std::vector<Transportation*> getCurrentList();
        // std::vector<Building*> getBuildings();
        bool operator=(Transportation* t);
        bool operator=(CityTraverser* t);
        bool operator=(std::vector<Transportation*> t);
        ~CityTraverser();

};

#endif