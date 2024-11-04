/**
 * @file TraversePassengerTrain.cpp
 * @brief Implementation of the TraversePassengerTrain class.
 * 
 * This file contains the implementation of the TraversePassengerTrain class, which provides 
 * methods to traverse through different lists of transportation elements related to passenger trains.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "TraversePassengerTrain.h"

/**
 * @brief Constructs a new TraversePassengerTrain object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraversePassengerTrain::TraversePassengerTrain(Transportation *element) : TraverseState(element) {}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraversePassengerTrain::nextList() {
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
bool TraversePassengerTrain::prevList() {
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
Transportation* TraversePassengerTrain::getPos(size_t x) {
    PassengerTrain *passengerTrain = static_cast<PassengerTrain*>(this->getLayer());

    switch (currentList) {
        case 0:
            return passengerTrain->getPassengerTrain(x);
        
        case 1:
            return passengerTrain->getInsideRoad(x);

        default:
            return nullptr;
    }
}