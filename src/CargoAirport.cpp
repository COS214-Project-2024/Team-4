/**
 * @file CargoAirport.cpp
 * @brief Implementation of the CargoAirport class.
 * 
 * This file contains the implementation of the CargoAirport class, which represents a cargo airport
 * and includes methods to manage inside roads and other cargo airports associated with it.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see CargoAirport.h
 */

#include "CargoAirport.h"

/**
 * @brief Constructor for CargoAirport.
 * 
 * Initializes the cargo airport with the given state and name.
 * 
 * @param state The state of the cargo airport.
 * @param name The name of the cargo airport.
 */
CargoAirport::CargoAirport(char state, std::string name) : Airport(state, name, 'C') {}

/**
 * @brief Adds an inside road to the cargo airport's list of inside roads.
 * @param insideRoad Pointer to the InsideRoad object.
 * @return True if the inside road was added, false if it already exists.
 */
bool CargoAirport::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads) {
        if(x == insideRoad) {
            return false;
        }
    }

    insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds a cargo airport to the cargo airport's list of cargo airports.
 * @param cargoAirport Pointer to the CargoAirport object.
 * @return True if the cargo airport was added, false if it already exists.
 */
bool CargoAirport::addCargoAirport(CargoAirport *cargoAirport) {
    for(CargoAirport *x : this->cargoAirports) {
        if(x == cargoAirport) {
            return false;
        }
    }

    cargoAirports.push_back(cargoAirport);
    return true;
}

/**
 * @brief Gets an inside road by index.
 * @param index The index of the inside road.
 * @return Pointer to the InsideRoad object, or nullptr if the index is out of range.
 */
InsideRoad* CargoAirport::getInsideRoad(std::size_t index) {
    if(index < insideRoads.size() && index >= 0) {
        return insideRoads[index];
    }

    return nullptr;
}

/**
 * @brief Gets a cargo airport by index.
 * @param index The index of the cargo airport.
 * @return Pointer to the CargoAirport object, or nullptr if the index is out of range.
 */
CargoAirport* CargoAirport::getCargoAirport(std::size_t index) {
    if(index < cargoAirports.size() && index >= 0) {
        return cargoAirports[index];
    }

    return nullptr;
}

/**
 * @brief Gets the name of the cargo airport.
 * @return The name of the cargo airport.
 */
std::string CargoAirport::getName() {
    return this->getAirportName();
}

/**
 * @brief Calculates the commute time for the cargo airport.
 * @return The commute time for the cargo airport.
 */
float CargoAirport::commuteTime(){
    return this->calculateCommute();
}