/**
 * @file AgregateTraverser.h
 * @brief Defines the AgregateTraverser class and its interface for creating CityTraverser objects.
 * 
 * This file contains the declaration of the AgregateTraverser class, which provides an interface
 * for creating CityTraverser objects. The AgregateTraverser class is an abstract base class with
 * pure virtual functions that must be implemented by derived classes.
 * 
 * The file also includes necessary headers for various transportation types and the CityTraverser class.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */

#ifndef AGREGATETRAVERSER_H
#define AGREGATETRAVERSER_H

#include <vector>
#include <variant>

#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"

#include "CityTraverser.h"

/**
 * @class AgregateTraverser
 * @brief Abstract base class for creating CityTraverser objects.
 * 
 * The AgregateTraverser class provides an interface for creating CityTraverser objects.
 * It declares pure virtual functions that must be implemented by derived classes to create
 * CityTraverser instances in different ways.
 */
class AgregateTraverser {
    public:
        /**
         * @brief Creates a new CityTraverser object.
         * @return A pointer to the newly created CityTraverser object.
         */
        virtual CityTraverser* createCityTraverser() = 0;

        /**
         * @brief Creates a new CityTraverser object with a given Transportation object.
         * @param t A pointer to a Transportation object.
         * @return A pointer to the newly created CityTraverser object.
         */
        virtual CityTraverser* createCityTraverser(Transportation *t) = 0;

        /**
         * @brief Creates a new CityTraverser object by copying an existing CityTraverser object.
         * @param t A pointer to an existing CityTraverser object.
         * @return A pointer to the newly created CityTraverser object.
         */
        virtual CityTraverser* createCityTraverser(CityTraverser *t) = 0;
};

#endif // AGREGATETRAVERSER_H