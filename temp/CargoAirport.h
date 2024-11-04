#ifndef CARGOAIRPORT_H
#define CARGOAIRPORT_H

#include "Airport.h"
#include "InsideRoad.h"

class InsideRoad;

class CargoAirport : public Airport {
    private:
        std::vector<InsideRoad*> insideRoads;
        std::vector<CargoAirport*> cargoAirports;

    public:
        CargoAirport(char state, std::string name);
        bool addInsideRoad(InsideRoad *insideRoad);
        bool addCargoAirport(CargoAirport *cargoAirport);
        InsideRoad* getInsideRoad(std::size_t index);
        CargoAirport* getCargoAirport(std::size_t index);
        std::string getName();
};

#endif