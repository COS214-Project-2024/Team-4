/**
 * @file Train.h
 * @brief Header file for the Train class.
 * 
 * This file contains the declaration of the Train class, which is a derived class of Transportation.
 * It includes methods to calculate the commute and get the train line.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAIN_H
#define TRAIN_H

#include "Transportation.h"

/**
 * @class Train
 * @brief A class representing a train as a mode of transportation.
 * 
 * The Train class inherits from the Transportation class and adds specific attributes
 * and methods related to trains, such as the train line and commute calculation.
 */
class Train : public Transportation {
    private:
        std::string line; ///< The line on which the train operates.

    public:
        /**
         * @brief Construct a new Train object.
         * 
         * @param state The state of the train.
         * @param line The line on which the train operates.
         * @param type The type of transportation.
         */
        Train(char state, std::string line, char type);

        /**
         * @brief Calculate the commute time for the train.
         * 
         * @return The calculated commute time.
         */
        float commuteTime();

        /**
         * @brief Get the line on which the train operates.
         * 
         * @return The train line.
         */
        std::string getLine();
};

#endif