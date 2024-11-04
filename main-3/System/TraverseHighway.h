/**
 * @file TraverseHighway.h
 * @brief Header file for the TraverseHighway class.
 *
 * This file contains the definition of the TraverseHighway class, which is a 
 * subclass of TraverseState. It provides functionality to traverse through 
 * highways in a transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSEHIGHWAY_H
#define TRAVERSEHIGHWAY_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"

/**
 * @class TraverseHighway
 * @brief A class to traverse through highways in a transportation system.
 *
 * The TraverseHighway class provides methods to navigate through a list of 
 * highways, allowing movement to the next or previous highway and retrieving 
 * the current position.
 */
class TraverseHighway: public TraverseState{
    private:
        int currentList = 0; ///< The current position in the list of highways.
        int upperBound = 1; ///< The upper bound of the list of highways.

    public:
        /**
         * @brief Constructor for TraverseHighway.
         * @param element A pointer to a Transportation object.
         */
        TraverseHighway(Transportation *element);

        /**
         * @brief Move to the next highway in the list.
         * @return True if the move was successful, false otherwise.
         */
        bool nextList();

        /**
         * @brief Move to the previous highway in the list.
         * @return True if the move was successful, false otherwise.
         */
        bool prevList();

        /**
         * @brief Get the Transportation object at the specified position.
         * @param x The position in the list.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);
};
#endif