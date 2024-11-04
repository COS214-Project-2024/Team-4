/**
 * @file TraverseFreightTrain.h
 * @brief Header file for the TraverseFreightTrain class.
 * 
 * This file contains the definition of the TraverseFreightTrain class, which is a subclass of TraverseState.
 * It provides functionality to traverse through a list of FreightTrain objects within a Transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSEFREIGHTTRAIN_H
#define TRAVERSEFREIGHTTRAIN_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "FreightTrain.h"

class Transportation;
class InsideRoad;
class FreightTrain;

/**
 * @class TraverseFreightTrain
 * @brief A class to traverse through FreightTrain objects.
 * 
 * The TraverseFreightTrain class provides methods to navigate through a list of FreightTrain objects
 * within a Transportation system. It maintains the current position within the list and allows moving
 * to the next or previous list.
 */
class TraverseFreightTrain: public TraverseState{
    private:
        int currentList = 0; ///< The current position in the list.
        int upperBound = 1; ///< The upper bound of the list.

    public:
        /**
         * @brief Constructor for TraverseFreightTrain.
         * 
         * Initializes a new instance of the TraverseFreightTrain class with the given Transportation element.
         * 
         * @param element A pointer to a Transportation object.
         */
        TraverseFreightTrain(Transportation *element);

        /**
         * @brief Move to the next list.
         * 
         * Advances the current position to the next list.
         * 
         * @return true if the operation was successful, false otherwise.
         */
        bool nextList();

        /**
         * @brief Move to the previous list.
         * 
         * Moves the current position to the previous list.
         * 
         * @return true if the operation was successful, false otherwise.
         */
        bool prevList();

        /**
         * @brief Get the position in the list.
         * 
         * Retrieves the Transportation object at the specified position in the list.
         * 
         * @param x The position in the list.
         * @return A pointer to the Transportation object at the specified position.
         */
        Transportation* getPos(size_t x);

};

#endif