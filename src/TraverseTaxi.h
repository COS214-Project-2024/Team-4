/**
 * @file TraverseTaxi.h
 * @brief Header file for the TraverseTaxi class.
 *
 * This file contains the definition of the TraverseTaxi class, which is a subclass of TraverseState.
 * The TraverseTaxi class is responsible for managing the traversal state of a Taxi object within 
 * a transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSETAXI_H
#define TRAVERSETAXI_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "Taxi.h"

class Transportation;
class InsideRoad;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;
class Taxi;

/**
 * @class TraverseTaxi
 * @brief Manages the traversal state of a Taxi object.
 *
 * The TraverseTaxi class provides functionality to traverse through different lists of transportation
 * elements, specifically for Taxi objects. It maintains the current list index and an upper bound for
 * the list index.
 */
class TraverseTaxi: public TraverseState{
    private:
        int currentList = 0; ///< The current list index.
        int upperBound = 4; ///< The upper bound for the list index.

    public:
        /**
         * @brief Constructor for TraverseTaxi.
         * @param element A pointer to a Transportation object.
         */
        TraverseTaxi(Transportation *element);

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
         * @brief Get the transportation element at the specified position.
         * @param x The position index.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);
};

#endif