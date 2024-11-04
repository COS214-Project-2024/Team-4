/**
 * @file Highway.cpp
 * @brief Implementation of the Highway class.
 * @version 1.0
 * 
 * This file contains the implementation of the Highway class, which inherits from the Road class.
 * The Highway class represents a highway with specific attributes and behaviors.
 */

#include "Highway.h"

/**
 * @brief Constructor for Highway.
 * @param state The state of the highway.
 * @param roadName The name of the highway.
 * @param speedLimit The speed limit of the highway.
 */
Highway::Highway(char state, std::string roadName, float speedLimit) : Road(state, roadName, 'H') {
    this->speedLimit = speedLimit;
}

/**
 * @brief Adds an InsideRoad to the highway.
 * @param insideRoad Pointer to the InsideRoad to be added.
 * @return True if the InsideRoad was added successfully, false if it already exists.
 */
bool Highway::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }

    this->insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds another Highway to the highway.
 * @param highway Pointer to the Highway to be added.
 * @return True if the Highway was added successfully, false if it already exists.
 */
bool Highway::addHighway(Highway *highway) {
    for(Highway *x: this->highways){
        if(x == highway){
            return false;
        }
    }

    this->highways.push_back(highway);
    return true;
}

/**
 * @brief Gets the name of the highway.
 * @return The name of the highway.
 */
std::string Highway::getRoadName() {
    return this->getName();
}

/**
 * @brief Gets an InsideRoad by index.
 * @param x The index of the InsideRoad.
 * @return Pointer to the InsideRoad if the index is valid, nullptr otherwise.
 */
InsideRoad *Highway::getInsideRoad(std::size_t x) {
    if(x < this->insideRoads.size() && x >= 0){
        return this->insideRoads[x];
    }else return nullptr;
} 

/**
 * @brief Gets a Highway by index.
 * @param x The index of the Highway.
 * @return Pointer to the Highway if the index is valid, nullptr otherwise.
 */
Highway *Highway::getHighway(std::size_t x) {
    if(x < this->highways.size() && x >= 0){
        return this->highways[x];
    }else return nullptr;
}

/**
 * @brief Gets the list of InsideRoads.
 * @return A vector of pointers to InsideRoads.
 */
std::vector<InsideRoad*> Highway::getInsideRoadsList() {
    return this->insideRoads;
}

/**
 * @brief Gets the list of Highways.
 * @return A vector of pointers to Highways.
 */
std::vector<Highway*> Highway::getHighwaysList() {
    return this->highways;
}

/**
 * @brief Gets the speed limit of the highway.
 * @return The speed limit of the highway.
 */
float Highway::getSpeedLimit() {
    return this->speedLimit;
}