/**
 * @file Bus.cpp
 * @brief Implementation of the Bus class.
 * 
 * This file contains the implementation of the Bus class, which represents a bus
 * as a type of public transit. It includes methods to manage inside roads, buses,
 * commercial airports, and passenger trains associated with the bus.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Bus.h
 */

#include "Bus.h"

/**
 * @brief Constructor for Bus.
 * 
 * Initializes the bus with the given state, route, bus number, and capacity.
 * 
 * @param state The state of the bus.
 * @param route The route of the bus.
 * @param busNumber The bus number.
 * @param capacity The capacity of the bus.
 */
Bus::Bus(char state, std::string route, int busNumber, int capacity) : PublicTransit(state, route, 'B') {
    this->busNumber = busNumber;
    this->capacity = capacity;
}

/**
 * @brief Adds an inside road to the bus's list of inside roads.
 * @param insideRoad Pointer to the InsideRoad object.
 * @return True if the inside road was added, false if it already exists.
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
 * @brief Adds a bus to the bus's list of buses.
 * @param bus Pointer to the Bus object.
 * @return True if the bus was added, false if it already exists.
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
 * @brief Adds a commercial airport to the bus's list of commercial airports.
 * @param comercialAirport Pointer to the ComercialAirport object.
 * @return True if the commercial airport was added, false if it already exists.
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
 * @brief Adds a passenger train to the bus's list of passenger trains.
 * @param passengerTrain Pointer to the PassengerTrain object.
 * @return True if the passenger train was added, false if it already exists.
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
 * @brief Gets an inside road by index.
 * @param x The index of the inside road.
 * @return Pointer to the InsideRoad object, or nullptr if the index is out of range.
 */
InsideRoad *Bus::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0){
        return insideRoads[x];
    }
    return nullptr;
}

/**
 * @brief Gets a bus by index.
 * @param x The index of the bus.
 * @return Pointer to the Bus object, or nullptr if the index is out of range.
 */
Bus *Bus::getBus(std::size_t x) {
    if(x < buses.size() && x >= 0){
        return buses[x];
    }
    return nullptr;
}

/**
 * @brief Gets a commercial airport by index.
 * @param x The index of the commercial airport.
 * @return Pointer to the ComercialAirport object, or nullptr if the index is out of range.
 */
ComercialAirport *Bus::getComercialAirport(std::size_t x) {
    if(x < comercialAirports.size() && x >= 0){
        return comercialAirports[x];
    }
    return nullptr;
}

/**
 * @brief Gets a passenger train by index.
 * @param x The index of the passenger train.
 * @return Pointer to the PassengerTrain object, or nullptr if the index is out of range.
 */
PassengerTrain *Bus::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0){
        return passengerTrains[x];
    }
    return nullptr;
}

/**
 * @brief Gets the bus number.
 * @return The bus number.
 */
int Bus::getBusNumber(){
    return this->busNumber;
}

/**
 * @brief Gets the capacity of the bus.
 * @return The capacity of the bus.
 */
int Bus::getCapacity(){
    return this->capacity;
}

/**
 * @brief Gets the route name of the bus.
 * @return The route name of the bus.
 */
std::string Bus::getRouteName() {
    return this->getRoute();
}

/**
 * @brief Calculates the commute time for the bus.
 * @return The commute time for the bus.
 */
float Bus::commuteTime(){
    return this->calculateCommute() + (this->capacity / 10);
}