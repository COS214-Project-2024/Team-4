#ifndef TAXI_H
#define TAXI_H

#include "PublicTransit.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"

class Taxi : public PublicTransit {
    private:
        std::string taxiCompany;
        int taxiNumber;

        std::vector<InsideRoad*> insideRoads;
        std::vector<ComercialAirport*> comercialAirports;
        std::vector<CargoAirport*> cargoAirports;
        std::vector<PassengerTrain*> passengerTrains;  
        std::vector<FreightTrain*> freightTrains;     

    public:
        Taxi(char state, std::string route, std::string taxiCompany, int taxiNumber);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addComercialAirport(ComercialAirport *comercialAirport);
        bool addCargoAirport(CargoAirport *cargoAirport);
        bool addPassengerTrain(PassengerTrain *passengerTrain);
        bool addFreightTrain(FreightTrain *freightTrain);
        InsideRoad *getInsideRoad(std::size_t x);
        ComercialAirport *getComercialAirport(std::size_t x);
        CargoAirport *getCargoAirport(std::size_t x);
        PassengerTrain *getPassengerTrain(std::size_t x);
        FreightTrain *getFreightTrain(std::size_t x);
        std::string getRoute();
        std::string getTaxiCompany();
        int getTaxiNumber();
};

#endif