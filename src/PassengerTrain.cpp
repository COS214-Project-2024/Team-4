/**
 * @file PassengerTrain.cpp
 * @brief Implementation of the PassengerTrain class.
 * @version 1.0
 * 
 * This file contains the implementation of the PassengerTrain class, which represents a passenger train
 * with specific attributes and behaviors.
 */

#include "PassengerTrain.h"

/**
 * @brief Constructor for PassengerTrain.
 * @param state The state of the passenger train.
 * @param line The line on which the passenger train operates.
 */
PassengerTrain::PassengerTrain(char state, std::string line) : Train(state, line, 'P') {}

/**
 * @brief Adds an InsideRoad to the passenger train.
 * @param insideRoad Pointer to the InsideRoad to be added.
 * @return True if the InsideRoad was added successfully, false if it already exists.
 */
bool PassengerTrain::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads) {
        if(x == insideRoad) {
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds another PassengerTrain to the passenger train.
 * @param passengerTrain Pointer to the PassengerTrain to be added.
 * @return True if the PassengerTrain was added successfully, false if it already exists.
 */
bool PassengerTrain::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x: this->passengerTrains) {
        if(x == passengerTrain) {
            return false;
        }
    }
    
    passengerTrains.push_back(passengerTrain);
    return true;
}

/**
 * @brief Gets an InsideRoad by index.
 * @param x The index of the InsideRoad.
 * @return Pointer to the InsideRoad if the index is valid, nullptr otherwise.
 */
InsideRoad *PassengerTrain::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0) {
        return insideRoads[x];
    }
    
    return nullptr;
}

/**
 * @brief Gets a PassengerTrain by index.
 * @param x The index of the PassengerTrain.
 * @return Pointer to the PassengerTrain if the index is valid, nullptr otherwise.
 */
PassengerTrain *PassengerTrain::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0) {
        return passengerTrains[x];
    }
    
    return nullptr;
}

/**
 * @brief Gets the line on which the passenger train operates.
 * @return The line of the passenger train.
 */
std::string PassengerTrain::getTrainLine() {
    return this->getLine();    
}