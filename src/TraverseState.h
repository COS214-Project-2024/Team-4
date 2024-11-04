/**
 * @file TraverseState.h
 * @brief Defines the TraverseState class and its interface for traversing through Transportation elements.
 * 
 * This file contains the definition of the TraverseState class, which provides an abstract interface for traversing through a list of Transportation elements.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#ifndef TRAVERSESTATE_H
#define TRAVERSESTATE_H

#include <vector>
#include "Transportation.h"

/**
 * @class TraverseState
 * @brief Abstract class that provides an interface for traversing through a list of Transportation elements.
 */
class TraverseState {
    private:
        Transportation *layer; ///< Pointer to the current Transportation layer.

    public:
        /**
         * @brief Constructor for TraverseState.
         * @param element Pointer to a Transportation element.
         */
        TraverseState(Transportation *element);

        /**
         * @brief Pure virtual function to move to the next list.
         * @return True if successful, false otherwise.
         */
        virtual bool nextList() = 0;

        /**
         * @brief Pure virtual function to move to the previous list.
         * @return True if successful, false otherwise.
         */
        virtual bool prevList() = 0;

        /**
         * @brief Pure virtual function to get the Transportation element at a specific position.
         * @param x Position index.
         * @return Pointer to the Transportation element at position x.
         */
        virtual Transportation* getPos(size_t x) = 0;

        /**
         * @brief Gets the current Transportation layer.
         * @return Pointer to the current Transportation layer.
         */
        Transportation* getLayer();
        virtual ~TraverseState() = default;
};

#endif // TRAVERSESTATE_H