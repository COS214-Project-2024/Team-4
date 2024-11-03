#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Transportation.h"
#include "TransportationFactory.h"

class TransportManager{
    private:
        TransportationFactory* factory;
        std::vector<Transportation*> transportations;

    public:
        TransportManager();
        bool createHighway(char state, std::string roadName, float speedLimit);
        bool createInsideRoad(char state, std::string roadName, float avgStopTime);
        bool createBus(char state, std::string route, int busNumber, int capacity);
        bool createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber);
        bool createPassengerTrain(char state, std::string line);
        bool createFreightTrain(char state, std::string line, float weight, float length);
        bool createComercialAirport(char state, std::string name);
        bool createCargoAirport(char state, std::string name);
        Transportation* getTransportation(size_t index);
        ~TransportManager();

};

#endif