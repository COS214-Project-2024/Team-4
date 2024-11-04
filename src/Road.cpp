/**
 * @file Road.cpp
 * @brief Implementation file for the Road class.
 * 
 * This file contains the implementation of the Road class, which represents a road 
 * in the transportation system.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#include "Road.h"

/**
 * @brief Constructs a new Road object.
 * 
 * @param state The state of the road.
 * @param roadName The name of the road.
 * @param type The type of the road.
 */
Road::Road(char state, std::string roadName, char type) : Transportation(state, type) {
    this->roadName = roadName;
}

/**
 * @brief Gets the name of the road.
 * 
 * @return The name of the road.
 */
std::string Road::getName() {
    return this->roadName;
}