/**
 * @file Road.h
 * @brief Defines the Road class which inherits from the Transportation class.
 * 
 * This file contains the declaration of the Road class, which represents a road 
 * as a type of transportation. It includes methods to calculate the commute 
 * and get the name of the road.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef ROAD_H
#define ROAD_H

#include "Transportation.h"

/**
 * @class Road
 * @brief A class representing a road as a type of transportation.
 * 
 * The Road class inherits from the Transportation class and adds specific 
 * attributes and methods related to roads.
 */
class Road : public Transportation {
    private:
        std::string roadName; ///< The name of the road.

    public:
        /**
         * @brief Constructs a new Road object.
         * 
         * @param state The state where the road is located.
         * @param roadName The name of the road.
         * @param type The type of the road.
         */
        Road(char state, std::string roadName, char type);

        /**
         * @brief Calculates the commute time on the road.
         * 
         * @return The calculated commute time.
         */
        float calculateCommute();

        /**
         * @brief Gets the name of the road.
         * 
         * @return The name of the road.
         */
        std::string getName();
};

#endif // ROAD_H