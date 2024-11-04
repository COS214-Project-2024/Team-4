/**
 * @file Highway.h
 * @brief Header file for the Highway class.
 * 
 * This file contains the definition of the Highway class, which inherits from the Road class.
 * The Highway class represents a highway with a speed limit and can contain multiple inside roads and other highways.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef HIGHWAY_H
#define HIGHWAY_H

#include <vector>

#include "Road.h"
#include "InsideRoad.h"

class InsideRoad;

/**
 * @class Highway
 * @brief Represents a highway with a speed limit.
 * 
 * The Highway class inherits from the Road class and includes additional attributes and methods
 * specific to highways, such as a speed limit and lists of inside roads and other highways.
 */
class Highway : public Road {
    private:
        float speedLimit; ///< The speed limit of the highway.
        std::vector<InsideRoad*> insideRoads; ///< List of inside roads connected to the highway.
        std::vector<Highway*> highways; ///< List of other highways connected to this highway.

    public:
        /**
         * @brief Constructs a Highway object.
         * 
         * @param state The state of the highway.
         * @param roadName The name of the highway.
         * @param speedLimit The speed limit of the highway.
         */
        Highway(char state, std::string roadName, float speedLimit);

        /**
         * @brief Adds an inside road to the highway.
         * 
         * @param insideRoad Pointer to the inside road to be added.
         * @return true if the inside road was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds another highway to this highway.
         * 
         * @param highway Pointer to the highway to be added.
         * @return true if the highway was added successfully, false otherwise.
         */
        bool addHighway(Highway *highway);

        /**
         * @brief Gets an inside road by index.
         * 
         * @param x The index of the inside road.
         * @return Pointer to the inside road at the specified index.
         */
        InsideRoad *getInsideRoad(std::size_t x);

        /**
         * @brief Gets a highway by index.
         * 
         * @param x The index of the highway.
         * @return Pointer to the highway at the specified index.
         */
        Highway *getHighway(std::size_t x);

        /**
         * @brief Gets the list of inside roads.
         * 
         * @return Vector of pointers to the inside roads.
         */
        std::vector<InsideRoad*> getInsideRoadsList();

        /**
         * @brief Gets the list of highways.
         * 
         * @return Vector of pointers to the highways.
         */
        std::vector<Highway*> getHighwaysList();

        /**
         * @brief Gets the name of the highway.
         * 
         * @return The name of the highway.
         */
        std::string getRoadName();

        /**
         * @brief Gets the speed limit of the highway.
         * 
         * @return The speed limit of the highway.
         */
        float getSpeedLimit();

        /**
         * @brief Calculates the adjusted commute time on the highway.
         * 
         * This function computes the commute time on the highway, taking into account
         * various factors such as speed limit, traffic conditions, and other relevant
         * parameters.
         * 
         * @return The adjusted commute time.
         */
        float commuteTime();
};

#endif // HIGHWAY_H