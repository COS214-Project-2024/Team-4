/**
 * @file Traverser.h
 * @brief Defines the Traverser interface for iterating over Transportation objects.
 * 
 * This file contains the declaration of the Traverser class, which provides an interface
 * for incrementing, decrementing, and dereferencing iterators over Transportation objects.
 *
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef TRAVERSER_H
#define TRAVERSER_H

#include "Transportation.h"

/**
 * @class Traverser
 * @brief Interface for iterating over Transportation objects.
 * 
 * The Traverser class provides pure virtual functions for incrementing, decrementing,
 * and dereferencing iterators over Transportation objects. Classes that inherit from
 * Traverser must implement these functions.
 */
class Traverser {
    public:
        /**
         * @brief Increment the iterator.
         * 
         * Pure virtual function to increment the iterator to the next Transportation object.
         * 
         * @return true if the increment was successful, false otherwise.
         */
        virtual bool operator++() = 0;

        /**
         * @brief Decrement the iterator.
         * 
         * Pure virtual function to decrement the iterator to the previous Transportation object.
         * 
         * @return true if the decrement was successful, false otherwise.
         */
        virtual bool operator--() = 0;

        /**
         * @brief Dereference the iterator.
         * 
         * Pure virtual function to dereference the iterator and access the current Transportation object.
         * 
         * @return Pointer to the current Transportation object.
         */
        virtual Transportation* operator*() = 0;
};

#endif // TRAVERSER_H