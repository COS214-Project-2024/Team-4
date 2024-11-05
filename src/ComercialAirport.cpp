/**
 * @file ComercialAirport.cpp
 * @brief Implementation of the ComercialAirport class.
 * 
 * This file contains the implementation of the ComercialAirport class, which represents a commercial airport
 * and includes methods to manage inside roads and other commercial airports associated with it.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see ComercialAirport.h
 */

#include "ComercialAirport.h"

/**
 * @brief Constructor for ComercialAirport.
 * 
 * Initializes the commercial airport with the given state and name.
 * 
 * @param state The state of the commercial airport.
 * @param name The name of the commercial airport.
 */
ComercialAirport::ComercialAirport(char state, std::string name) : Airport(state, name, 'C') {}

/**
 * @brief Adds a commercial airport to the commercial airport's list of commercial airports.
 * @param comercialAirport Pointer to the ComercialAirport object.
 * @return True if the commercial airport was added, false if it already exists.
 */
bool ComercialAirport::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x: this->comercialAirports) {
        if(x == comercialAirport) {
            return false;
        }
    }
    
    comercialAirports.push_back(comercialAirport);
    return true;
}

/**
 * @brief Gets an inside road by index.
 * @param index The index of the inside road.
 * @return Pointer to the InsideRoad object, or nullptr if the index is out of range.
 */
InsideRoad* ComercialAirport::getRoad(std::size_t index) {
    if(index < roads.size() && index >= 0) {
        return roads[index];
    }
    
    return nullptr;
}

/**
 * @brief Gets a commercial airport by index.
 * @param index The index of the commercial airport.
 * @return Pointer to the ComercialAirport object, or nullptr if the index is out of range.
 */
ComercialAirport* ComercialAirport::getComercialAirport(std::size_t index) {
    if(index < comercialAirports.size() && index >= 0) {
        return comercialAirports[index];
    }
    
    return nullptr;
}

/**
 * @brief Gets the name of the commercial airport.
 * @return The name of the commercial airport.
 */
std::string ComercialAirport::getName() {
    return this->getAirportName();
}

/**
 * @brief Calculates the commute time for the commercial airport.
 * @return The commute time for the commercial airport.
 */
float ComercialAirport::commuteTime() {
    return this->calculateCommute();
}