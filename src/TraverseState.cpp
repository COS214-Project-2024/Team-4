/**
 * @file TraverseState.cpp
 * @brief Implementation of the TraverseState class.
 * 
 * This file contains the implementation of the TraverseState class, which is responsible for managing the state of transportation layers.
 * 
 * @version 1.0
 * @date 2023-10-01
 * 
 */

#include "TraverseState.h"

/**
 * @brief Construct a new TraverseState object.
 * 
 * @param layer Pointer to the Transportation layer.
 */
TraverseState::TraverseState(Transportation *layer){
    this->layer = layer;
}

/**
 * @brief Get the Transportation layer.
 * 
 * @return Transportation* Pointer to the Transportation layer.
 */
Transportation* TraverseState::getLayer(){
    return this->layer;
}