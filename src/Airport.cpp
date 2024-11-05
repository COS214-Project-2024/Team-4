/**
 * @file Airport.cpp
 * @brief Implementation of the Airport class.
 * 
 * This file contains the implementation of the Airport class, which represents an airport
 * as a type of transportation. It includes methods to get the airport name and calculate
 * the commute time.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Airport.h
 */

#include "Airport.h"

Airport::Airport(char state, std::string name, char type) : Transportation(state, type) {
    this->name = name;
}

/**
 * @brief Gets the name of the airport.
 * @return The name of the airport.
 */
std::string Airport::getAirportName() {
    return name;
}

/**
 * @brief Calculates the commute time to the airport.
 * @return The commute time to the airport.
 */
float Airport::calculateCommute() {
    return 20.0;
}