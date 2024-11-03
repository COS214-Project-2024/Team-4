#ifndef TRANSPORTATIONFACTORY_H
#define TRANSPORTATIONFACTORY_H

#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"

class TransportationFactory{
    public:
        Transportation* createHighway(char state, std::string roadName, float speedLimit);
        Transportation* createInsideRoad(char state, std::string roadName, float avgStopTime);
        Transportation* createBus(char state, std::string route, int busNumber, int capacity);
        Transportation* createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber);
        Transportation* createPassengerTrain(char state, std::string line);
        Transportation* createFreightTrain(char state, std::string line, float weight, float length);
        Transportation* createComercialAirport(char state, std::string name);
        Transportation* createCargoAirport(char state, std::string name);

};

#endif