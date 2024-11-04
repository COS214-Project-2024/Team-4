/**
 * @file Bus.cpp
 * @brief Implementation of the Bus class.
 * 
 * This file contains the implementation of the Bus class, which is a derived class from PublicTransit.
 * It includes methods to add and retrieve inside roads, buses, commercial airports, and passenger trains.
 * It also includes methods to get the bus number, capacity, and route name.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing different types of public transportation.
 */

#include "Bus.h"

/**
 * @brief Construct a new Bus object.
 * 
 * @param state The state where the bus operates.
 * @param route The route of the bus.
 * @param busNumber The bus number.
 * @param capacity The capacity of the bus.
 */
Bus::Bus(char state, std::string route, int busNumber, int capacity) : PublicTransit(state, route, 'B') {
    this->busNumber = busNumber;
    this->capacity = capacity;
}

/**
 * @brief Adds an inside road to the bus's route.
 * 
 * @param insideRoad Pointer to the inside road to be added.
 * @return true if the inside road was added successfully.
 * @return false if the inside road is already in the list.
 */
bool Bus::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
 
    insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds a bus to the list of buses.
 * 
 * @param bus Pointer to the bus to be added.
 * @return true if the bus was added successfully.
 * @return false if the bus is already in the list.
 */
bool Bus::addBus(Bus *bus) {
    for(Bus *x : this->buses){
        if(x == bus){
            return false;
        }
    }
 
    buses.push_back(bus);
    return true;
}

/**
 * @brief Adds a commercial airport to the list of commercial airports.
 * 
 * @param comercialAirport Pointer to the commercial airport to be added.
 * @return true if the commercial airport was added successfully.
 * @return false if the commercial airport is already in the list.
 */
bool Bus::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }
 
    comercialAirports.push_back(comercialAirport);
    return true;
}

/**
 * @brief Adds a passenger train to the list of passenger trains.
 * 
 * @param passengerTrain Pointer to the passenger train to be added.
 * @return true if the passenger train was added successfully.
 * @return false if the passenger train is already in the list.
 */
bool Bus::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }
 
    passengerTrains.push_back(passengerTrain);
    return true;
}

/**
 * @brief Gets an inside road from the list of inside roads.
 * 
 * @param x The index of the inside road to retrieve.
 * @return InsideRoad* Pointer to the inside road, or nullptr if the index is out of range.
 */
InsideRoad *Bus::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0){
        return insideRoads[x];
    }
    return nullptr;
}

/**
 * @brief Gets a bus from the list of buses.
 * 
 * @param x The index of the bus to retrieve.
 * @return Bus* Pointer to the bus, or nullptr if the index is out of range.
 */
Bus *Bus::getBus(std::size_t x) {
    if(x < buses.size() && x >= 0){
        return buses[x];
    }
    return nullptr;
}

/**
 * @brief Gets a commercial airport from the list of commercial airports.
 * 
 * @param x The index of the commercial airport to retrieve.
 * @return ComercialAirport* Pointer to the commercial airport, or nullptr if the index is out of range.
 */
ComercialAirport *Bus::getComercialAirport(std::size_t x) {
    if(x < comercialAirports.size() && x >= 0){
        return comercialAirports[x];
    }
    return nullptr;
}

/**
 * @brief Gets a passenger train from the list of passenger trains.
 * 
 * @param x The index of the passenger train to retrieve.
 * @return PassengerTrain* Pointer to the passenger train, or nullptr if the index is out of range.
 */
PassengerTrain *Bus::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0){
        return passengerTrains[x];
    }
    return nullptr;
}

/**
 * @brief Gets the bus number.
 * 
 * @return int The bus number.
 */
int Bus::getBusNumber(){
    return this->busNumber;
}

/**
 * @brief Gets the capacity of the bus.
 * 
 * @return int The capacity of the bus.
 */
int Bus::getCapacity(){
    return this->capacity;
}

/**
 * @brief Gets the route name of the bus.
 * 
 * @return std::string The route name of the bus.
 */
std::string Bus::getRouteName() {
    return this->getRoute();
}