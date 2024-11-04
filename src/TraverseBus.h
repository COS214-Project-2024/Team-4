/**
 * @file TraverseBus.h
 * @brief Header file for the TraverseBus class.
 * 
 * This file contains the definition of the TraverseBus class, which is a 
 * concrete implementation of the TraverseState interface. The TraverseBus 
 * class is responsible for managing the traversal state of a bus within 
 * a transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSEBUS_H
#define TRAVERSEBUS_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "ComercialAirport.h"
#include "PassengerTrain.h"

class Transportation;
class InsideRoad;
class Bus;
class ComercialAirport;
class PassengerTrain;

/**
 * @class TraverseBus
 * @brief A class to manage the traversal state of a bus.
 * 
 * The TraverseBus class provides functionality to traverse through different 
 * lists of transportation elements, such as buses, commercial airports, and 
 * passenger trains. It maintains the current list and provides methods to 
 * navigate to the next or previous list.
 */
class TraverseBus: public TraverseState{
    private:
        int currentList = 0; ///< The current list index.
        int upperBound = 3; ///< The upper bound for the list index.

    public:
        /**
         * @brief Constructor for TraverseBus.
         * 
         * Initializes a new instance of the TraverseBus class with the given 
         * transportation element.
         * 
         * @param element A pointer to a Transportation object.
         */
        TraverseBus(Transportation *element);

        /**
         * @brief Move to the next list.
         * 
         * Advances the current list index to the next list, if possible.
         * 
         * @return True if the list was successfully advanced, false otherwise.
         */
        bool nextList();

        /**
         * @brief Move to the previous list.
         * 
         * Moves the current list index to the previous list, if possible.
         * 
         * @return True if the list was successfully moved back, false otherwise.
         */
        bool prevList();

        /**
         * @brief Get the transportation element at the specified position.
         * 
         * Retrieves the transportation element at the given position within 
         * the current list.
         * 
         * @param x The position index within the current list.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);

};

#endif