#ifndef AGREGATETRAVERSER_H
#define AGREGATETRAVERSER_H

#include <vector>
#include <variant>

#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"

#include "CityTraverser.h"

class Transportation;

class AgregateTraverser {
    public:
        virtual CityTraverser* createCityTraverser() = 0;
        virtual CityTraverser* createCityTraverser(Transportation *t) = 0;
};

#endif