/**
 * @file TransportationFactory.h
 * @brief Header file for the TransportationFactory class.
 *
 * This file contains the declaration of the TransportationFactory class, which is responsible for creating various types of transportation objects.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRANSPORTATIONFACTORY_H
#define TRANSPORTATIONFACTORY_H

#include "Transportation.h"
#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "Taxi.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"

/**
 * @class TransportationFactory
 * @brief A factory class for creating different types of transportation objects.
 */
class TransportationFactory{
    public:
        /**
         * @brief Creates a Highway object.
         * @param state The state of the highway.
         * @param roadName The name of the road.
         * @param speedLimit The speed limit of the highway.
         * @return A pointer to the created Highway object.
         */
        Transportation* createHighway(char state, std::string roadName, float speedLimit);

        /**
         * @brief Creates an InsideRoad object.
         * @param state The state of the inside road.
         * @param roadName The name of the road.
         * @param avgStopTime The average stop time on the road.
         * @return A pointer to the created InsideRoad object.
         */
        Transportation* createInsideRoad(char state, std::string roadName, float avgStopTime);

        /**
         * @brief Creates a Bus object.
         * @param state The state of the bus.
         * @param route The route of the bus.
         * @param busNumber The bus number.
         * @param capacity The capacity of the bus.
         * @return A pointer to the created Bus object.
         */
        Transportation* createBus(char state, std::string route, int busNumber, int capacity);

        /**
         * @brief Creates a Taxi object.
         * @param state The state of the taxi.
         * @param route The route of the taxi.
         * @param taxiCompany The company of the taxi.
         * @param taxiNumber The taxi number.
         * @return A pointer to the created Taxi object.
         */
        Transportation* createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber);

        /**
         * @brief Creates a PassengerTrain object.
         * @param state The state of the passenger train.
         * @param line The line of the passenger train.
         * @return A pointer to the created PassengerTrain object.
         */
        Transportation* createPassengerTrain(char state, std::string line);

        /**
         * @brief Creates a FreightTrain object.
         * @param state The state of the freight train.
         * @param line The line of the freight train.
         * @param weight The weight of the freight.
         * @param length The length of the freight train.
         * @return A pointer to the created FreightTrain object.
         */
        Transportation* createFreightTrain(char state, std::string line, float weight, float length);

        /**
         * @brief Creates a ComercialAirport object.
         * @param state The state of the commercial airport.
         * @param name The name of the commercial airport.
         * @return A pointer to the created ComercialAirport object.
         */
        Transportation* createComercialAirport(char state, std::string name);

        /**
         * @brief Creates a CargoAirport object.
         * @param state The state of the cargo airport.
         * @param name The name of the cargo airport.
         * @return A pointer to the created CargoAirport object.
         */
        Transportation* createCargoAirport(char state, std::string name);
};

#endif // TRANSPORTATIONFACTORY_H