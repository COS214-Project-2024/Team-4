/**
 * @file Transportation.h
 * @brief Header file for the Transportation class.
 * 
 * This file contains the declaration of the Transportation class, which is used to manage 
 * traffic flow states and types of transportation.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRANSPORTATION_H
#define TRANSPORTATION_H

#include <iostream>

#include "TrafficFlow.h"
#include "Peak.h"
#include "NonPeak.h"
#include "LunchRush.h"

/**
 * @class Transportation
 * @brief Manages traffic flow states and types of transportation.
 * 
 * The Transportation class provides methods to get and set the traffic flow state and type 
 * of transportation. It also includes a destructor to clean up resources.
 */
class Transportation {
    private:
        TrafficFlow *state; ///< Pointer to the current traffic flow state.
        char type; ///< Type of transportation.
    public:
        /**
         * @brief Constructor for the Transportation class.
         * 
         * Initializes the Transportation object with the given state and type.
         * 
         * @param state Initial state of the traffic flow.
         * @param type Type of transportation.
         */
        Transportation(char state, char type);

        /**
         * @brief Pure virtual function to calculate the commute time.
         * 
         * This function must be overridden by any derived class to provide
         * the specific implementation for calculating the commute time.
         * 
         * @return float The calculated commute time.
         */
        virtual float commuteTime() = 0;

        /**
         * @brief Gets the current traffic flow.
         * 
         * @return The current traffic flow as a float.
         */
        float getTrafficFlow();

        /**
         * @brief Sets the traffic flow state.
         * 
         * Updates the traffic flow state to the given state.
         * 
         * @param state New state of the traffic flow.
         * @return True if the state was successfully updated, false otherwise.
         */
        bool setState(char state);

        /**
         * @brief Gets the type of transportation.
         * 
         * @return The type of transportation as a char.
         */
        char getType();

        /**
         * @brief Destructor for the Transportation class.
         * 
         * Cleans up resources used by the Transportation object.
         */
        ~Transportation();
};

#endif