#ifndef INSIDEROAD_H
#define INSIDEROAD_H

#include <vector>
#include <iostream>

#include "Road.h"
#include "Highway.h"
#include "Bus.h"
#include "Taxi.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
// #include "Building.h"

class Highway;
class Bus;
class Taxi;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;


class InsideRoad : public Road {
    private:
        float avgStopTime;
        std::vector<InsideRoad*> insideRoads;
        std::vector<Highway*> highways;
        std::vector<Bus*> buses;
        std::vector<Taxi*> taxis;
        std::vector<ComercialAirport*> comercialAirports;
        std::vector<CargoAirport*> cargoAirports;
        std::vector<PassengerTrain*> passengerTrains;
        std::vector<FreightTrain*> freightTrains;
        // std::vector<Building*> buildings;

    public:
        InsideRoad(char state, std::string roadName, float avgStopTime);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addHighway(Highway *highway);
        bool addBus(Bus *bus);  
        bool addTaxi(Taxi *taxi);
        bool addComercialAirport(ComercialAirport *comercialAirport);
        bool addCargoAirport(CargoAirport *cargoAirport);
        bool addPassengerTrain(PassengerTrain *passengerTrain);
        bool addFreightTrain(FreightTrain *freightTrain); 
        // bool addBuilding(Building *building); 
        FreightTrain* getFreightTrain(std::size_t x);
        PassengerTrain* getPassengerTrain(std::size_t x);
        Highway* getHighway(std::size_t x);
        InsideRoad* getInsideRoad(std::size_t x);
        Bus* getBus(std::size_t x);
        Taxi* getTaxi(std::size_t x);
        ComercialAirport* getComercialAirport(std::size_t x);
        CargoAirport* getCargoAirport(std::size_t x);
        // Building *getBuilding(std::size_t x);
        // std::vector<Building*> getBuildingsList();   
        float getAvgStopTime();
        std::string getRoadName();

}; 

#endif