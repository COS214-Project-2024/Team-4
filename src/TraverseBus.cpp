/**
 * @file TraverseBus.cpp
 * @brief Implementation of the TraverseBus class.
 * 
 * This file contains the implementation of the TraverseBus class, which provides 
 * methods to traverse through different lists of transportation elements related to buses.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "TraverseBus.h"

/**
 * @brief Constructs a new TraverseBus object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseBus::TraverseBus(Transportation *element) : TraverseState(element) {}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseBus::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

/**
 * @brief Moves to the previous list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseBus::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

/**
 * @brief Gets the transportation element at the specified position.
 * 
 * @param x The position of the transportation element.
 * @return Pointer to the transportation element, or nullptr if the position is invalid.
 */
Transportation* TraverseBus::getPos(size_t x) {
    Bus *temp = static_cast<Bus*>(this->getLayer());

    switch(currentList) {
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getBus(x);

        case 2:
            return temp->getComercialAirport(x);

        case 3:
            return temp->getPassengerTrain(x);

        default:
            return nullptr;
    }
}