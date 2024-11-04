/**
 * @file TransportManager.cpp
 * @brief Implementation of the TransportManager class.
 * 
 * This file contains the implementation of the TransportManager class, which manages 
 * the creation and storage of various transportation objects using the TransportationFactory.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TransportManager.h"

/**
 * @brief Constructs a new TransportManager object.
 */
TransportManager::TransportManager(){
    factory = new TransportationFactory();
}

/**
 * @brief Creates a Highway object and adds it to the transportation list.
 * 
 * @param state The state of the highway.
 * @param roadName The name of the road.
 * @param speedLimit The speed limit of the highway.
 * @return True if the highway was created successfully, false otherwise.
 */
bool TransportManager::createHighway(char state, std::string roadName, float speedLimit){
    Transportation* highway = factory->createHighway(state, roadName, speedLimit);
    if(highway != nullptr){
        transportations.push_back(highway);
        return true;
    }
    return false;
}

/**
 * @brief Creates an InsideRoad object and adds it to the transportation list.
 * 
 * @param state The state of the inside road.
 * @param roadName The name of the road.
 * @param avgStopTime The average stop time on the road.
 * @return True if the inside road was created successfully, false otherwise.
 */
bool TransportManager::createInsideRoad(char state, std::string roadName, float avgStopTime){
    Transportation* insideRoad = factory->createInsideRoad(state, roadName, avgStopTime);
    if(insideRoad != nullptr){
        transportations.push_back(insideRoad);
        return true;
    }
    return false;
}

/**
 * @brief Creates a Bus object and adds it to the transportation list.
 * 
 * @param state The state of the bus.
 * @param route The route of the bus.
 * @param busNumber The bus number.
 * @param capacity The capacity of the bus.
 * @return True if the bus was created successfully, false otherwise.
 */
bool TransportManager::createBus(char state, std::string route, int busNumber, int capacity){
    Transportation* bus = factory->createBus(state, route, busNumber, capacity);
    if(bus != nullptr){
        transportations.push_back(bus);
        return true;
    }
    return false;
}

/**
 * @brief Creates a Taxi object and adds it to the transportation list.
 * 
 * @param state The state of the taxi.
 * @param route The route of the taxi.
 * @param taxiCompany The company of the taxi.
 * @param taxiNumber The taxi number.
 * @return True if the taxi was created successfully, false otherwise.
 */
bool TransportManager::createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber){
    Transportation* taxi = factory->createTaxi(state, route, taxiCompany, taxiNumber);
    if(taxi != nullptr){
        transportations.push_back(taxi);
        return true;
    }
    return false;
}

/**
 * @brief Creates a PassengerTrain object and adds it to the transportation list.
 * 
 * @param state The state of the passenger train.
 * @param line The line of the passenger train.
 * @return True if the passenger train was created successfully, false otherwise.
 */
bool TransportManager::createPassengerTrain(char state, std::string line){
    Transportation* passengerTrain = factory->createPassengerTrain(state, line);
    if(passengerTrain != nullptr){
        transportations.push_back(passengerTrain);
        return true;
    }
    return false;
}

/**
 * @brief Creates a FreightTrain object and adds it to the transportation list.
 * 
 * @param state The state of the freight train.
 * @param line The line of the freight train.
 * @param weight The weight of the freight.
 * @param length The length of the freight train.
 * @return True if the freight train was created successfully, false otherwise.
 */
bool TransportManager::createFreightTrain(char state, std::string line, float weight, float length){
    Transportation* freightTrain = factory->createFreightTrain(state, line, weight, length);
    if(freightTrain != nullptr){
        transportations.push_back(freightTrain);
        return true;
    }
    return false;
}

/**
 * @brief Creates a ComercialAirport object and adds it to the transportation list.
 * 
 * @param state The state of the commercial airport.
 * @param name The name of the commercial airport.
 * @return True if the commercial airport was created successfully, false otherwise.
 */
bool TransportManager::createComercialAirport(char state, std::string name){
    Transportation* comercialAirport = factory->createComercialAirport(state, name);
    if(comercialAirport != nullptr){
        transportations.push_back(comercialAirport);
        return true;
    }
    return false;
}

/**
 * @brief Creates a CargoAirport object and adds it to the transportation list.
 * 
 * @param state The state of the cargo airport.
 * @param name The name of the cargo airport.
 * @return True if the cargo airport was created successfully, false otherwise.
 */
bool TransportManager::createCargoAirport(char state, std::string name){
    Transportation* cargoAirport = factory->createCargoAirport(state, name);
    if(cargoAirport != nullptr){
        transportations.push_back(cargoAirport);
        return true;
    }
    return false;
}

/**
 * @brief Gets a transportation object by index.
 * 
 * @param index The index of the transportation object.
 * @return A pointer to the transportation object, or nullptr if the index is out of range.
 */
Transportation* TransportManager::getTransportation(size_t index){
    if(index < transportations.size() && index >= 0){
        return transportations[index];
    }
    return nullptr;
}

/**
 * @brief Destroys the TransportManager object and cleans up resources.
 */
TransportManager::~TransportManager(){
    for(Transportation* transportation : transportations){
        delete transportation;
    }

    delete factory;
}