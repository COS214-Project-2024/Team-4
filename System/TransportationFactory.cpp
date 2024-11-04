#include "TransportationFactory.h"

Transportation* TransportationFactory::createHighway(char state, std::string roadName, float speedLimit){
    if(speedLimit < 100){
        return nullptr;
    }

    if(roadName == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new Highway(state, roadName, speedLimit);
}

Transportation* TransportationFactory::createInsideRoad(char state, std::string roadName, float avgStopTime){
    if(avgStopTime <= 0){
        return nullptr;
    }

    if(roadName == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new InsideRoad(state, roadName, avgStopTime);
}

Transportation* TransportationFactory::createBus(char state, std::string route, int busNumber, int capacity){
    if(busNumber <= 0 || capacity <= 0){
        return nullptr;
    }
    
    if(route == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new Bus(state, route, busNumber, capacity);
}

Transportation* TransportationFactory::createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber){
    if(taxiNumber <= 0){
        return nullptr;
    }
    
    if(route == "" || taxiCompany == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }


    return new Taxi(state, route, taxiCompany, taxiNumber);
}

Transportation* TransportationFactory::createPassengerTrain(char state, std::string line){
    if(line == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new PassengerTrain(state, line);
}

Transportation* TransportationFactory::createFreightTrain(char state, std::string line, float weight, float length){
        if(weight <= 0 || length <= 0){
        return nullptr;
    }
    
    if(line == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }


    return new FreightTrain(state, line, weight, length);
}

Transportation* TransportationFactory::createComercialAirport(char state, std::string name){
    
    if(name == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new ComercialAirport(state, name);
}

Transportation* TransportationFactory::createCargoAirport(char state, std::string name){    
    if(name == ""){
        return nullptr;
    }

    if(state != 'P' || state != 'N' || state != 'L'){
        return nullptr;
    }

    return new CargoAirport(state, name);
}

