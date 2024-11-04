/**
 * @file PublicTransit.cpp
 * @brief Implementation of the PublicTransit class.
 * @version 1.0
 * 
 * This file contains the implementation of the PublicTransit class, which represents a public transit
 * system with specific attributes and behaviors.
 */

#include "PublicTransit.h"

/**
 * @brief Constructor for PublicTransit.
 * @param state The state of the public transit.
 * @param route The route of the public transit.
 * @param type The type of the public transit.
 */
PublicTransit::PublicTransit(char state, std::string route, char type) : Transportation(state, type) {
    this->route = route;
}

/**
 * @brief Gets the route of the public transit.
 * @return The route of the public transit.
 */
std::string PublicTransit::getRoute() {
    return route;
}