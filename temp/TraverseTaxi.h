#ifndef TRAVERSETAXI_H
#define TRAVERSETAXI_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "Taxi.h"

class Transportation;
class InsideRoad;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;
class Taxi;

class TraverseTaxi: public TraverseState{
    private:
        int currentList = 0;
        int upperBound = 4;

    public:
        TraverseTaxi(Transportation *element);
        bool nextList();
        bool prevList();
        Transportation* getPos(size_t x);
        // std::vector<Building*> getBuildings()        

};

#endif