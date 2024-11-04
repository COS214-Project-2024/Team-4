/**
 * @file TraverseComercialAirport.cpp
 * @brief Implementation of the TraverseComercialAirport class.
 * 
 * This file contains the implementation of the TraverseComercialAirport class, which provides 
 * methods to traverse through different lists of transportation elements related to commercial airports.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "TraverseComercialAirport.h"

/**
 * @brief Constructs a new TraverseComercialAirport object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseComercialAirport::TraverseComercialAirport(Transportation *element) : TraverseState(element) {}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseComercialAirport::nextList() {
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
bool TraverseComercialAirport::prevList() {
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
Transportation* TraverseComercialAirport::getPos(size_t x) {
    ComercialAirport *comercialAirport = static_cast<ComercialAirport*>(this->getLayer());

    switch(currentList) {
        case 0:
            return comercialAirport->getRoad(x);
     
        case 1:
            return comercialAirport->getComercialAirport(x);
     
        default:
            return nullptr;
    }
}