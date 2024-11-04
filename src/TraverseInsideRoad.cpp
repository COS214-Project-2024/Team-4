/**
 * @file TraverseInsideRoad.cpp
 * @brief Implementation of the TraverseInsideRoad class.
 * 
 * This file contains the implementation of the TraverseInsideRoad class, which provides 
 * methods to traverse through different lists of transportation elements related to inside roads.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TraverseInsideRoad.h"

/**
 * @brief Constructs a new TraverseInsideRoad object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseInsideRoad::TraverseInsideRoad(Transportation *element) : TraverseState(element) {}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseInsideRoad::nextList() {
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
bool TraverseInsideRoad::prevList() {
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
Transportation* TraverseInsideRoad::getPos(size_t x) {
    InsideRoad *temp = static_cast<InsideRoad*>(this->getLayer());

    switch(currentList){
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getHighway(x);   

        case 2:
            return temp->getBus(x);

        case 3:
            return temp->getTaxi(x);

        case 4:
            return temp->getComercialAirport(x);

        case 5:
            return temp->getCargoAirport(x);

        case 6:
            return temp->getPassengerTrain(x);

        case 7:
            return temp->getFreightTrain(x);

        default:
            return nullptr;
    }
}