#include "TransportManager.h"

TransportManager::TransportManager(){
    factory = new TransportationFactory();
}

bool TransportManager::createHighway(char state, std::string roadName, float speedLimit){
    Transportation* highway = factory->createHighway(state, roadName, speedLimit);
    if(highway != nullptr){
        transportations.push_back(highway);
        return true;
    }
    return false;
}

bool TransportManager::createInsideRoad(char state, std::string roadName, float avgStopTime){
    Transportation* insideRoad = factory->createInsideRoad(state, roadName, avgStopTime);
    if(insideRoad != nullptr){
        transportations.push_back(insideRoad);
        return true;
    }
    return false;
}

bool TransportManager::createBus(char state, std::string route, int busNumber, int capacity){
    Transportation* bus = factory->createBus(state, route, busNumber, capacity);
    if(bus != nullptr){
        transportations.push_back(bus);
        return true;
    }
    return false;
}

bool TransportManager::createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber){
    Transportation* taxi = factory->createTaxi(state, route, taxiCompany, taxiNumber);
    if(taxi != nullptr){
        transportations.push_back(taxi);
        return true;
    }
    return false;
}

bool TransportManager::createPassengerTrain(char state, std::string line){
    Transportation* passengerTrain = factory->createPassengerTrain(state, line);
    if(passengerTrain != nullptr){
        transportations.push_back(passengerTrain);
        return true;
    }
    return false;
}

bool TransportManager::createFreightTrain(char state, std::string line, float weight, float length){
    Transportation* freightTrain = factory->createFreightTrain(state, line, weight, length);
    if(freightTrain != nullptr){
        transportations.push_back(freightTrain);
        return true;
    }
    return false;
}

bool TransportManager::createComercialAirport(char state, std::string name){
    Transportation* comercialAirport = factory->createComercialAirport(state, name);
    if(comercialAirport != nullptr){
        transportations.push_back(comercialAirport);
        return true;
    }
    return false;
}

bool TransportManager::createCargoAirport(char state, std::string name){
    Transportation* cargoAirport = factory->createCargoAirport(state, name);
    if(cargoAirport != nullptr){
        transportations.push_back(cargoAirport);
        return true;
    }
    return false;
}

Transportation* TransportManager::getTransportation(size_t index){
    if(index < transportations.size() && index >= 0){
        return transportations[index];
    }
    return nullptr;
}

TransportManager::~TransportManager(){
    for(Transportation* transportation : transportations){
        delete transportation;
    }

    delete factory;
}

