#ifndef BUS_H
#define BUS_H

#include <vector>

#include "PublicTransit.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "PassengerTrain.h"
#include "Building.h"

class Bus : public PublicTransit {
    private:

        int busNumber;
        int capacity;
        std::vector<InsideRoad*> insideRoads;
        std::vector<Bus*> buses; 
        std::vector<ComercialAirport*> comercialAirports;
        std::vector<PassengerTrain*> passengerTrains;
        std::vector<Building*> buildings;

    public:

        Bus(char state, std::string route, int busNumber, int capacity);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addBus(Bus *bus);
        bool addComercialAirport(ComercialAirport *comercialAirport);
        bool addPassengerTrain(PassengerTrain *passengerTrain);
        bool addBuilding(Building *building);
        InsideRoad *getInsideRoad(std::size_t x);
        Bus *getBus(std::size_t x);
        ComercialAirport *getComercialAirport(std::size_t x);
        PassengerTrain *getPassengerTrain(std::size_t x);
        Building *getBuilding(std::size_t x);
        int getBusNumber();
        int getCapacity();
        std::string getRoute();

};

#endif