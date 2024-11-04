/**
 * @file TraverseTaxi.cpp
 * @brief Implementation of the TraverseTaxi class.
 * 
 * This file contains the implementation of the TraverseTaxi class, which provides specific traversal logic for Taxi transportation elements.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "TraverseTaxi.h"

/**
 * @brief Construct a new TraverseTaxi object.
 * 
 * @param element Pointer to a Transportation element.
 */
TraverseTaxi::TraverseTaxi(Transportation *element) : TraverseState(element) {}

/**
 * @brief Move to the next list of transportation elements.
 * 
 * @return True if successful, false otherwise.
 */
bool TraverseTaxi::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

/**
 * @brief Move to the previous list of transportation elements.
 * 
 * @return True if successful, false otherwise.
 */
bool TraverseTaxi::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

/**
 * @brief Get the Transportation element at a specific position.
 * 
 * @param x Position index.
 * @return Pointer to the Transportation element at position x.
 */
Transportation* TraverseTaxi::getPos(size_t x) {
    Taxi *taxi = static_cast<Taxi*>(this->getLayer());
    
    switch (currentList) {
        case 0:
            return taxi->getInsideRoad(x);
        case 1:
            return taxi->getComercialAirport(x);
        case 2:
            return taxi->getCargoAirport(x);
        case 3:
            return taxi->getPassengerTrain(x);
        case 4:
            return taxi->getFreightTrain(x);
        default:
            return nullptr;
    }
}