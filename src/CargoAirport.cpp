#include "CargoAirport.h"

CargoAirport::CargoAirport(char state, std::string name) : Airport(state, name, 'C') {}

bool CargoAirport::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads) {
        if(x == insideRoad) {
            return false;
        }
    }

    insideRoads.push_back(insideRoad);
    return true;
}

bool CargoAirport::addCargoAirport(CargoAirport *cargoAirport) {
    for(CargoAirport *x : this->cargoAirports) {
        if(x == cargoAirport) {
            return false;
        }
    }

    cargoAirports.push_back(cargoAirport);
    return true;
}

InsideRoad* CargoAirport::getInsideRoad(std::size_t index) {
    if(index < insideRoads.size() && index >= 0) {
        return insideRoads[index];
    }

    return nullptr;
}

CargoAirport* CargoAirport::getCargoAirport(std::size_t index) {
    if(index < cargoAirports.size() && index >= 0) {
        return cargoAirports[index];
    }

    return nullptr;
}

std::string CargoAirport::getName() {
    return this->getAirportName();
}

float CargoAirport::commuteTime(){
    return this->calculateCommute();
}