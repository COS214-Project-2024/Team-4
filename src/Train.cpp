/**
 * @file Train.cpp
 * @brief Implementation of the Train class.
 * 
 * This file contains the implementation of the Train class, which represents a train 
 * in the transportation system.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "Train.h"

/**
 * @brief Constructs a new Train object.
 * 
 * @param state The state of the train.
 * @param line The line on which the train operates.
 * @param type The type of transportation.
 */
Train::Train(char state, std::string line, char type) : Transportation(state, type) {
    this->line = line;
}

/**
 * @brief Gets the line on which the train operates.
 * 
 * @return The line on which the train operates.
 */
std::string Train::getLine() {
    return line;
}