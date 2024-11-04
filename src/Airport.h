/**
 * @file Airport.h
 * @brief Defines the Airport class which inherits from the Transportation class.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */

#ifndef AIRPORT_H
#define AIRPORT_H

#include "Transportation.h"

/**
 * @class Airport
 * @brief Represents an airport as a type of transportation.
 */
class Airport : public Transportation {
    public:
        /**
         * @brief Name of the airport.
         */
        std::string name;

    public:
        /**
         * @brief Constructs an Airport object.
         * @param state The state where the airport is located.
         * @param name The name of the airport.
         * @param type The type of transportation.
         */
        Airport(char state, std::string name, char type);

        /**
         * @brief Calculates the commute time to the airport.
         * @return The commute time as a float.
         */
        float calculateCommute();

        /**
         * @brief Gets the name of the airport.
         * @return The name of the airport as a string.
         */
        std::string getAirportName();
};

#endif