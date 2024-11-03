#ifndef BUS_H
#define BUS_H

#include <vector>

#include "PublicTransit.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "PassengerTrain.h"

class InsideRoad;
class ComercialAirport;
class PassengerTrain;

class Bus : public PublicTransit {
    private:

        int busNumber;
        int capacity;
        std::vector<InsideRoad*> insideRoads;
        std::vector<Bus*> buses; 
        std::vector<ComercialAirport*> comercialAirports;
        std::vector<PassengerTrain*> passengerTrains;

    public:

        Bus(char state, std::string route, int busNumber, int capacity);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addBus(Bus *bus);
        bool addComercialAirport(ComercialAirport *comercialAirport);
        bool addPassengerTrain(PassengerTrain *passengerTrain);
        InsideRoad *getInsideRoad(std::size_t x);
        Bus *getBus(std::size_t x);
        ComercialAirport *getComercialAirport(std::size_t x);
        PassengerTrain *getPassengerTrain(std::size_t x);
        int getBusNumber();
        int getCapacity();
        std::string getRouteName();

};

#endif