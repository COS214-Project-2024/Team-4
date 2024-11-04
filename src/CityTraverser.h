//CONCRETE ITERATOR

#ifndef CITYTRAVERSER_h
#define CITYTRAVERSER_h

#include <vector>

#include "Traverser.h"
#include "Transportation.h"
#include "TraverseState.h"
#include "TraverseHighway.h"
#include "TraverseInsideRoad.h"
#include "TraverseBus.h"
#include "TraverseTaxi.h"
#include "TraverseFreightTrain.h"
#include "TraversePassengerTrain.h"
#include "TraverseCargoAirport.h"
#include "TraverseComercialAirport.h"
// #include "Building.h"

class Transportation;
class Traverser;
// class Building;

class CityTraverser: public Traverser{
    private:
        TraverseState *state;
        int currentElement;
        Transportation* Element;
        std::vector<Transportation*> prevLayers;
        Transportation* currentLayer;
        char dataType;

    public:
        CityTraverser();
        CityTraverser(Transportation* t);
        CityTraverser(CityTraverser* t);
        bool operator++();
        bool operator--();
        bool operator+();
        bool operator-();
        bool stepIn();
        bool stepOut();
        Transportation* operator*();
        Transportation* getCurrentLayer();
        // std::vector<Building*> getBuildings();
        bool operator=(Transportation* t);
        bool operator=(CityTraverser* t);
        bool setState();
        ~CityTraverser();

};

#endif