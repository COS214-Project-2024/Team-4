/**
 * @file TraverseInsideRoad.h
 * @brief Header file for the TraverseInsideRoad class.
 *
 * This file contains the definition of the TraverseInsideRoad class, which is a 
 * state class used to traverse inside roads in a transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSEINSIDEROAD_H
#define TRAVERSEINSIDEROAD_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"

/**
 * @class TraverseInsideRoad
 * @brief A class to traverse inside roads in a transportation system.
 *
 * The TraverseInsideRoad class is a state class that allows traversal of inside roads
 * within a transportation system. It inherits from the TraverseState class.
 */
class TraverseInsideRoad: public TraverseState{
    private:
        int currentList = 0; ///< The current list index.
        int upperBound = 7; ///< The upper bound for the list index.

    public:
        /**
         * @brief Constructor for TraverseInsideRoad.
         * @param element A pointer to a Transportation object.
         */
        TraverseInsideRoad(Transportation *element);

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
         * @brief Get the Transportation object at the specified position.
         * @param x The position index.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);
};

#endif // TRAVERSEINSIDEROAD_H