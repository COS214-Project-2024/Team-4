/**
 * @file Airport.cpp
 * @brief Implementation of the Airport class.
 * 
 * This file contains the implementation of the Airport class, which is a derived class
 * from the Transportation class. It includes the constructor and the method to get the
 * airport name.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing different types of transportation.
 * 
 */
#include "Airport.h"

/**
 * @brief Construct a new Airport object.
 * 
 * @param state The state where the airport is located.
 * @param name The name of the airport.
 * @param type The type of transportation.
 */
Airport::Airport(char state, std::string name, char type) : Transportation(state, type) {
    this->name = name;
}

/**
 * @brief Get the name of the airport.
 * 
 * @return std::string The name of the airport.
 */
std::string Airport::getAirportName() {
    return name;
}