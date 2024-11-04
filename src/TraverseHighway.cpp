/**
 * @file TraverseHighway.cpp
 * @brief Implementation of the TraverseHighway class.
 * 
 * This file contains the implementation of the TraverseHighway class, which provides 
 * methods to traverse through different lists of transportation elements related to highways.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TraverseHighway.h"

/**
 * @brief Constructs a new TraverseHighway object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseHighway::TraverseHighway(Transportation *element): TraverseState(element){
    currentList = 0;
}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseHighway::nextList(){
    if(currentList < upperBound){
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
bool TraverseHighway::prevList(){
    if(currentList > 0){
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
Transportation* TraverseHighway::getPos(size_t x){
    Highway *temp = static_cast<Highway*>(this->getLayer());

    switch(this->currentList){
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getHighway(x);

        default:
            return nullptr;
    }
}