/**
 * @file CityTraverser.h
 * @brief Header file for the CityTraverser class, a concrete iterator for traversing transportation elements in a city.
 * 
 * This file contains the definition of the CityTraverser class, which is responsible for iterating over various 
 * transportation elements within a city. It provides methods for moving forward and backward through the elements, 
 * stepping into and out of layers, and accessing the current element.
 * 
 * @note This class is part of the iterator pattern implementation.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef CITYTRAVERSER_h
#define CITYTRAVERSER_h

#include <vector>

#include "Traverser.h"
#include "Transportation.h"
#include "TraverseState.h"
#include "TraverseHighway.h"
#include "TraverseInsideRoad.h"
#include "TraverseBus.h"
#include "TraverseTaxi.h"
#include "TraverseFreightTrain.h"
#include "TraversePassengerTrain.h"
#include "TraverseCargoAirport.h"
#include "TraverseComercialAirport.h"

/**
 * @class CityTraverser
 * @brief A concrete iterator for traversing transportation elements in a city.
 * 
 * The CityTraverser class provides functionality to iterate over various transportation elements within a city. 
 * It maintains the current state of traversal and allows moving forward and backward through the elements, 
 * as well as stepping into and out of layers.
 */
class CityTraverser: public Traverser {
    private:
        TraverseState *state; ///< The current state of traversal.
        int currentElement; ///< The index of the current element.
        Transportation* Element; ///< The current transportation element.
        std::vector<Transportation*> prevLayers; ///< Stack of previous layers.
        Transportation* currentLayer; ///< The current layer of transportation elements.
        char dataType; ///< The type of data being traversed.

    public:
        /**
         * @brief Default constructor for CityTraverser.
         */
        CityTraverser();

        /**
         * @brief Constructor for CityTraverser with a starting transportation element.
         * @param t Pointer to the starting transportation element.
         */
        CityTraverser(Transportation* t);

        /**
         * @brief Copy constructor for CityTraverser.
         * @param t Pointer to another CityTraverser object to copy from.
         */
        CityTraverser(CityTraverser* t);

        /**
         * @brief Move to the next transportation element.
         * @return True if successful, false otherwise.
         */
        bool operator++();

        /**
         * @brief Move to the previous transportation element.
         * @return True if successful, false otherwise.
         */
        bool operator--();

        /**
         * @brief Move forward in the current layer.
         * @return True if successful, false otherwise.
         */
        bool operator+();

        /**
         * @brief Move backward in the current layer.
         * @return True if successful, false otherwise.
         */
        bool operator-();

        /**
         * @brief Step into the current layer of transportation elements.
         * @return True if successful, false otherwise.
         */
        bool stepIn();

        /**
         * @brief Step out to the current layer of transportation elements.
         * @return True if successful, false otherwise.
         */
        bool stepOut();

        /**
         * @brief Dereference operator to access the current transportation element.
         * @return Pointer to the current transportation element.
         */
        Transportation* operator*();

        /**
         * @brief Get the current layer of transportation elements.
         * @return Pointer to the current layer of transportation elements.
         */
        Transportation* getCurrentLayer();

        /**
         * @brief Assignment operator to set the current transportation layer.
         * @param t Pointer to the transportation element to set.
         * @return True if successful, false otherwise.
         */
        bool set(Transportation* t);

        /**
         * @brief Assignment operator to copy from another CityTraverser object.
         * @param t Pointer to the CityTraverser object to copy from.
         * @return True if successful, false otherwise.
         */
        bool set(CityTraverser* t);

        /**
         * @brief Set the current state of traversal.
         * @return True if successful, false otherwise.
         */
        bool setState();

        /**
         * @brief Destructor for CityTraverser.
         */
        ~CityTraverser();
};

#endif