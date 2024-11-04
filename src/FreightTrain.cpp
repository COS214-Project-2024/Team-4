/**
 * @file FreightTrain.cpp
 * @brief Implementation of the FreightTrain class.
 * @version 1.0
 * 
 * This file contains the implementation of the FreightTrain class, which inherits from the Train class.
 * The FreightTrain class represents a freight train with specific attributes and behaviors.
 */

#include "FreightTrain.h"

/**
 * @brief Constructor for FreightTrain.
 * @param state The state of the freight train.
 * @param line The line on which the freight train operates.
 * @param weight The weight of the freight train.
 * @param length The length of the freight train.
 */
FreightTrain::FreightTrain(char state, std::string line, float weight, float length) : Train(state, line, 'F') {
    this->weight = weight;
    this->length = length;
}

/**
 * @brief Adds an InsideRoad to the freight train.
 * @param insideRoad Pointer to the InsideRoad to be added.
 * @return True if the InsideRoad was added successfully, false if it already exists.
 */
bool FreightTrain::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds another FreightTrain to the freight train.
 * @param freightTrain Pointer to the FreightTrain to be added.
 * @return True if the FreightTrain was added successfully, false if it already exists.
 */
bool FreightTrain::addFreightTrain(FreightTrain *freightTrain) {
    for(FreightTrain *x: this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }
    
    freightTrains.push_back(freightTrain);
    return true;
}

/**
 * @brief Gets an InsideRoad by index.
 * @param index The index of the InsideRoad.
 * @return Pointer to the InsideRoad if the index is valid, nullptr otherwise.
 */
InsideRoad *FreightTrain::getInsideRoad(size_t index){
    if(index < insideRoads.size() && index >= 0){
        return insideRoads[index];
    }
    return nullptr;
}

/**
 * @brief Gets a FreightTrain by index.
 * @param index The index of the FreightTrain.
 * @return Pointer to the FreightTrain if the index is valid, nullptr otherwise.
 */
FreightTrain *FreightTrain::getFreightTrain(size_t index){
    if(index < freightTrains.size() && index >= 0){
        return freightTrains[index];
    }
    return nullptr;
}

/**
 * @brief Gets the weight of the freight train.
 * @return The weight of the freight train.
 */
float FreightTrain::getWeight(){
    return weight;
}

/**
 * @brief Gets the length of the freight train.
 * @return The length of the freight train.
 */
float FreightTrain::getLength(){
    return length;
}

/**
 * @brief Gets the line on which the freight train operates.
 * @return The line of the freight train.
 */
std::string FreightTrain::getTrainLine(){
    return this->getLine();
}