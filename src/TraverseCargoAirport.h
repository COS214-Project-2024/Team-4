/**
 * @file TraverseCargoAirport.h
 * @brief Header file for the TraverseCargoAirport class.
 *
 * This file contains the definition of the TraverseCargoAirport class, which is a subclass of TraverseState.
 * It provides functionality to traverse through a cargo airport using different lists.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSECARGOAIRPORT_H
#define TRAVERSECARGOAIRPORT_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "CargoAirport.h"

class Transportation;
class InsideRoad;
class CargoAirport;

/**
 * @class TraverseCargoAirport
 * @brief A class to traverse through a cargo airport.
 *
 * The TraverseCargoAirport class provides methods to navigate through different lists within a cargo airport.
 */
class TraverseCargoAirport: public TraverseState{
    private:
        int currentList = 0; /**< The current list being traversed. */
        int upperBound = 1; /**< The upper bound of the list index. */

    public:
        /**
         * @brief Constructor for TraverseCargoAirport.
         * @param element A pointer to a Transportation object.
         */
        TraverseCargoAirport(Transportation *element);

        /**
         * @brief Move to the next list.
         * @return True if the operation was successful, false otherwise.
         */
        bool nextList();

        /**
         * @brief Move to the previous list.
         * @return True if the operation was successful, false otherwise.
         */
        bool prevList();

        /**
         * @brief Get the position of a specific element in the current list.
         * @param x The index of the element.
         * @return A pointer to the Transportation object at the specified index.
         */
        Transportation* getPos(size_t x);
};

#endif