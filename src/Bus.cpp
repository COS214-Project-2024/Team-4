#include "Bus.h"

Bus::Bus(char state, std::string route, int busNumber, int capacity) : PublicTransit(state, route, 'B') {
    this->busNumber = busNumber;
    this->capacity = capacity;
}

bool Bus::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
 
    insideRoads.push_back(insideRoad);
    return true;
}

bool Bus::addBus(Bus *bus) {
    for(Bus *x : this->buses){
        if(x == bus){
            return false;
        }
    }
 
    buses.push_back(bus);
    return true;
}

bool Bus::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }
 
    comercialAirports.push_back(comercialAirport);
    return true;
}


bool Bus::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }
 
    passengerTrains.push_back(passengerTrain);
    return true;
}


InsideRoad *Bus::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0){
        return insideRoads[x];
    }
    return nullptr;
}

Bus *Bus::getBus(std::size_t x) {
    if(x < buses.size() && x >= 0){
        return buses[x];
    }
    return nullptr;
}

ComercialAirport *Bus::getComercialAirport(std::size_t x) {
    if(x < comercialAirports.size() && x >= 0){
        return comercialAirports[x];
    }
    return nullptr;
}


PassengerTrain *Bus::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0){
        return passengerTrains[x];
    }
    return nullptr;
}


int Bus::getBusNumber(){
    return this->busNumber;
}

int Bus::getCapacity(){
    return this->capacity;
}

std::string Bus::getRouteName() {
    return this->getRoute();
}

float Bus::commuteTime(){
    return this->commuteTime() + (this->capacity/10);
    
}