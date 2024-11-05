/**
 * @file FreightTrain.cpp
 * @brief Implementation of the FreightTrain class.
 * 
 * This file contains the implementation of the FreightTrain class, which represents a freight train
 * and includes methods to manage inside roads and other freight trains associated with it.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see FreightTrain.h
 */

#include "FreightTrain.h"

/**
 * @brief Constructor for FreightTrain.
 * 
 * Initializes the freight train with the given state, line, weight, and length.
 * 
 * @param state The state of the freight train.
 * @param line The line of the freight train.
 * @param weight The weight of the freight train.
 * @param length The length of the freight train.
 */
FreightTrain::FreightTrain(char state, std::string line, float weight, float length)
    : Train(state, line, 'F'), weight(weight), length(length) {}

/**
 * @brief Adds a freight train to the freight train's list of freight trains.
 * @param freightTrain Pointer to the FreightTrain object.
 * @return True if the freight train was added, false if it already exists.
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
 * @brief Gets an inside road by index.
 * @param index The index of the inside road.
 * @return Pointer to the InsideRoad object, or nullptr if the index is out of range.
 */
InsideRoad *FreightTrain::getInsideRoad(size_t index){
    if(index < insideRoads.size() && index >= 0){
        return insideRoads[index];
    }
    return nullptr;
}

/**
 * @brief Gets a freight train by index.
 * @param index The index of the freight train.
 * @return Pointer to the FreightTrain object, or nullptr if the index is out of range.
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
 * @brief Gets the train line of the freight train.
 * @return The train line of the freight train.
 */
std::string FreightTrain::getTrainLine(){
    return this->getLine();
}

/**
 * @brief Calculates the commute time for the freight train.
 * @return The commute time for the freight train.
 */
float FreightTrain::commuteTime(){
    return this->calculateCommute() * (1 + weight / 1000 + length / 100);    
}