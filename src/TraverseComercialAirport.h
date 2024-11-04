/**
 * @file TraverseComercialAirport.h
 * @brief Header file for the TraverseComercialAirport class.
 * 
 * This file contains the definition of the TraverseComercialAirport class, 
 * which is a subclass of TraverseState. It provides functionality to traverse 
 * through a commercial airport using different lists.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSECOMERCIALAIRPORT_H
#define TRAVERSECOMERCIALAIRPORT_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"

class Transportation;
class InsideRoad;
class ComercialAirport;

/**
 * @class TraverseComercialAirport
 * @brief A class to traverse through a commercial airport.
 * 
 * The TraverseComercialAirport class provides methods to navigate through 
 * different lists within a commercial airport. It maintains the current 
 * position and allows moving to the next or previous list.
 */
class TraverseComercialAirport: public TraverseState{
    private:
        int currentList = 0; ///< The current list index.
        int upperBound = 1; ///< The upper bound for the list index.

    public:
        /**
         * @brief Constructor for TraverseComercialAirport.
         * 
         * Initializes the TraverseComercialAirport with a given Transportation element.
         * 
         * @param element A pointer to a Transportation object.
         */
        TraverseComercialAirport(Transportation *element);

        /**
         * @brief Move to the next list.
         * 
         * Advances the current list index to the next list.
         * 
         * @return true if the operation was successful, false otherwise.
         */
        bool nextList();

        /**
         * @brief Move to the previous list.
         * 
         * Moves the current list index to the previous list.
         * 
         * @return true if the operation was successful, false otherwise.
         */
        bool prevList();

        /**
         * @brief Get the position of a specific element.
         * 
         * Retrieves the Transportation object at the specified position.
         * 
         * @param x The index of the desired element.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);
};

#endif