/**
 * @file TraversePassengerTrain.h
 * @brief Header file for the TraversePassengerTrain class.
 * 
 * This file contains the definition of the TraversePassengerTrain class, which is used to traverse 
 * through a passenger train in a transportation system.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAVERSEPASSENGERTRAIN_H
#define TRAVERSEPASSENGERTRAIN_H

#include <vector>

#include "TraverseState.h"
#include "Transportation.h"
#include "InsideRoad.h"
#include "PassengerTrain.h"

class Transportation;
class InsideRoad;
class PassengerTrain;

/**
 * @class TraversePassengerTrain
 * @brief A class to traverse through a passenger train.
 * 
 * The TraversePassengerTrain class provides functionality to traverse through a passenger train 
 * by maintaining the current position and bounds within the train.
 */
class TraversePassengerTrain: public TraverseState{
    private:
        int currentList = 0; ///< The current position in the list.
        int upperBound = 1; ///< The upper bound of the list.

    public:
        /**
         * @brief Constructor for TraversePassengerTrain.
         * 
         * Initializes a new instance of the TraversePassengerTrain class.
         * 
         * @param element A pointer to a Transportation object.
         */
        TraversePassengerTrain(Transportation *element);

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
         * @brief Get the position at the specified index.
         * 
         * Retrieves the Transportation object at the specified index.
         * 
         * @param x The index of the position to retrieve.
         * @return A pointer to the Transportation object at the specified index.
         */
        Transportation* getPos(size_t x);
};

#endif