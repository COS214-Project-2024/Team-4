/**
 * @file PublicTransit.h
 * @brief Header file for the PublicTransit class.
 * 
 * This file contains the declaration of the PublicTransit class, which is a 
 * subclass of the Transportation class. It represents a public transit 
 * system with a specific route.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef PUBLICTRANSIT_H
#define PUBLICTRANSIT_H

#include <iostream>
#include "Transportation.h"

/**
 * @class PublicTransit
 * @brief A class representing public transit transportation.
 * 
 * The PublicTransit class inherits from the Transportation class and adds 
 * specific attributes and methods related to public transit systems.
 */
class PublicTransit : public Transportation {
    private:
        std::string route; ///< The route of the public transit.

    public:
        /**
         * @brief Constructor for the PublicTransit class.
         * 
         * @param state The state of the transportation.
         * @param route The route of the public transit.
         * @param type The type of the transportation.
         */
        PublicTransit(char state, std::string route, char type);

        /**
         * @brief Calculate the commute time for the public transit.
         * 
         * @return The calculated commute time.
         */
        float calculateCommute();

        /**
         * @brief Get the route of the public transit.
         * 
         * @return The route as a string.
         */
        std::string getRoute();
};

#endif // PUBLICTRANSIT_H