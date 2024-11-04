/**
 * @file ComercialAirport.cpp
 * @brief Implementation of the ComercialAirport class.
 *
 * This file contains the implementation of the ComercialAirport class which manages commercial airports.
 * 
 * @version 1.0
 */

#include "ComercialAirport.h"

/**
 * @brief Constructor for ComercialAirport.
 *
 * Initializes the commercial airport with a state and name.
 * 
 * @param state The state of the airport.
 * @param name The name of the airport.
 */
ComercialAirport::ComercialAirport(char state, std::string name) : Airport(state, name, 'A') {}

/**
 * @brief Adds a road to the commercial airport.
 *
 * Adds a road to the list of roads if it is not already present.
 * 
 * @param road Pointer to the InsideRoad object.
 * @return True if the road was added, false otherwise.
 */
bool ComercialAirport::addRoad(InsideRoad *road) {
    for(InsideRoad *x: this->roads) {
        if(x == road) {
            return false;
        }
    }
    
    roads.push_back(road);
    return true;
}

/**
 * @brief Adds a commercial airport to the list.
 *
 * Adds a commercial airport to the list of commercial airports if it is not already present.
 * 
 * @param comercialAirport Pointer to the ComercialAirport object.
 * @return True if the commercial airport was added, false otherwise.
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
 * @brief Gets a road by index.
 *
 * Retrieves a road from the list of roads by its index.
 * 
 * @param index The index of the road.
 * @return Pointer to the InsideRoad object if found, nullptr otherwise.
 */
InsideRoad* ComercialAirport::getRoad(std::size_t index) {
    if(index < roads.size() && index >= 0) {
        return roads[index];
    }
    
    return nullptr;
}

/**
 * @brief Gets a commercial airport by index.
 *
 * Retrieves a commercial airport from the list of commercial airports by its index.
 * 
 * @param index The index of the commercial airport.
 * @return Pointer to the ComercialAirport object if found, nullptr otherwise.
 */
ComercialAirport* ComercialAirport::getComercialAirport(std::size_t index) {
    if(index < comercialAirports.size() && index >= 0) {
        return comercialAirports[index];
    }
    
    return nullptr;
}

/**
 * @brief Gets the name of the commercial airport.
 *
 * @return The name of the commercial airport.
 */
std::string ComercialAirport::getName() {
    return this->getAirportName();
}