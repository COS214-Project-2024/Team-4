#include "Taxi.h"

Taxi::Taxi(char state, std::string route, std::string taxiCompany, int taxiNumber) : PublicTransit(state, route) {
    this->taxiCompany = taxiCompany;
    this->taxiNumber = taxiNumber;
}

bool Taxi::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

bool Taxi::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }
    
    comercialAirports.push_back(comercialAirport);
    return true;
}

bool Taxi::addCargoAirport(CargoAirport *cargoAirport) {
    for(CargoAirport *x : this->cargoAirports){
        if(x == cargoAirport){
            return false;
        }
    }
    
    cargoAirports.push_back(cargoAirport);
    return true;
}

bool Taxi::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }
    
    passengerTrains.push_back(passengerTrain);
    return true;
}

bool Taxi::addFreightTrain(FreightTrain *freightTrain) {
    for(FreightTrain *x : this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }
    
    freightTrains.push_back(freightTrain);
    return true;
}   

InsideRoad *Taxi::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size()&& x >= 0){
        return insideRoads[x];
    }
    return nullptr;
}

ComercialAirport *Taxi::getComercialAirport(std::size_t x) {
    if(x < comercialAirports.size()&& x >= 0){
        return comercialAirports[x];
    }
    return nullptr;
}

CargoAirport *Taxi::getCargoAirport(std::size_t x) {
    if(x < cargoAirports.size()&& x >= 0){
        return cargoAirports[x];
    }
    return nullptr;
}

PassengerTrain *Taxi::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size()&& x >= 0){
        return passengerTrains[x];
    }
    return nullptr;
}

FreightTrain *Taxi::getFreightTrain(std::size_t x) {
    if(x < freightTrains.size()&& x >= 0){
        return freightTrains[x];
    }
    return nullptr;
}

std::string Taxi::getRoute() {
    return this->getRoute();
}

std::string Taxi::getTaxiCompany() {
    return this->taxiCompany;
}

int Taxi::getTaxiNumber() {
    return this->taxiNumber;
}