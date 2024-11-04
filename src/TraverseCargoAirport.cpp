/**
 * @file TraverseCargoAirport.cpp
 * @brief Implementation of the TraverseCargoAirport class.
 * 
 * This file contains the implementation of the TraverseCargoAirport class, which provides 
 * methods to traverse through different lists of transportation elements related to cargo airports.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TraverseCargoAirport.h"

/**
 * @brief Constructs a new TraverseCargoAirport object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseCargoAirport::TraverseCargoAirport(Transportation *element) : TraverseState(element) {}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseCargoAirport::nextList() {
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
bool TraverseCargoAirport::prevList() {
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
Transportation* TraverseCargoAirport::getPos(size_t x) {
    CargoAirport *cargoAirport = static_cast<CargoAirport*>(this->getLayer());

    switch(currentList) {
        case 0:
            return cargoAirport->getInsideRoad(x);
     
        case 1:
            return cargoAirport->getCargoAirport(x);
     
        default:
            return nullptr;
    }
}