/**
 * @file TraverseFreightTrain.cpp
 * @brief Implementation of the TraverseFreightTrain class.
 * 
 * This file contains the implementation of the TraverseFreightTrain class, which provides 
 * methods to traverse through different lists of transportation elements related to freight trains.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "TraverseFreightTrain.h"

/**
 * @brief Constructs a new TraverseFreightTrain object.
 * 
 * @param element Pointer to the Transportation element.
 */
TraverseFreightTrain::TraverseFreightTrain(Transportation *element) : TraverseState(element){}

/**
 * @brief Moves to the next list of transportation elements.
 * 
 * @return True if the move was successful, false otherwise.
 */
bool TraverseFreightTrain::nextList(){
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
bool TraverseFreightTrain::prevList(){
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
Transportation* TraverseFreightTrain::getPos(size_t x){
    FreightTrain *freightTrain = static_cast<FreightTrain*>(this->getLayer());

    switch(currentList){
        case 0:
            return freightTrain->getFreightTrain(x);
        
        case 1:
            return freightTrain->getInsideRoad(x);

        default:
            return nullptr;
    }
}