/**
 * @file createTraverser.h
 * @brief Header file for the CreateTraverser class.
 *
 * This file contains the definition of the CreateTraverser class, which is a subclass of AgregateTraverser.
 * The CreateTraverser class provides methods to create instances of CityTraverser.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef CREATETRAVERSER_H
#define CREATETRAVERSER_H

#include <vector>
#include "AgregateTraverser.h"
#include "Transportation.h"
#include "CityTraverser.h"

class AgregateTraverser;
class Transportation;
class CityTraverser;

/**
 * @class CreateTraverser
 * @brief A class to create CityTraverser instances.
 *
 * The CreateTraverser class inherits from AgregateTraverser and provides methods to create CityTraverser objects.
 */
class CreateTraverser : public AgregateTraverser {
    public:
        /**
         * @brief Creates a new CityTraverser instance.
         * @return A pointer to the newly created CityTraverser instance.
         */
        CityTraverser* createCityTraverser();

        /**
         * @brief Creates a new CityTraverser instance with a specified Transportation object.
         * @param t A pointer to a Transportation object.
         * @return A pointer to the newly created CityTraverser instance.
         */
        CityTraverser* createCityTraverser(Transportation *t);

        /**
         * @brief Creates a new CityTraverser instance by copying an existing CityTraverser object.
         * @param t A pointer to an existing CityTraverser object.
         * @return A pointer to the newly created CityTraverser instance.
         */
        CityTraverser* createCityTraverser(CityTraverser *t);
};

#endif // CREATETRAVERSER_H