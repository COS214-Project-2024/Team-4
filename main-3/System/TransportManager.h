/**
 * @file TransportManager.h
 * @brief Header file for the TransportManager class.
 * 
 * This file contains the definition of the TransportManager class, which is responsible for managing various types of transportation objects.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRANSPORTMANAGER_H
#define TRANSPORTMANAGER_H

#include "Transportation.h"
#include "TransportationFactory.h"

/**
 * @class TransportManager
 * @brief Manages various types of transportation objects.
 * 
 * The TransportManager class uses a TransportationFactory to create and manage different types of transportation objects such as highways, roads, buses, taxis, trains, and airports.
 */
class TransportManager {
    private:
        TransportationFactory* factory; ///< Pointer to the factory used to create transportation objects.
        std::vector<Transportation*> transportations; ///< Vector to store created transportation objects.

    public:
        /**
         * @brief Constructor for the TransportManager class.
         */
        TransportManager();

        /**
         * @brief Creates a highway.
         * 
         * @param state The state where the highway is located.
         * @param roadName The name of the highway.
         * @param speedLimit The speed limit of the highway.
         * @return True if the highway was created successfully, false otherwise.
         */
        bool createHighway(char state, std::string roadName, float speedLimit);

        /**
         * @brief Creates an inside road.
         * 
         * @param state The state where the road is located.
         * @param roadName The name of the road.
         * @param avgStopTime The average stop time on the road.
         * @return True if the road was created successfully, false otherwise.
         */
        bool createInsideRoad(char state, std::string roadName, float avgStopTime);

        /**
         * @brief Creates a bus.
         * 
         * @param state The state where the bus operates.
         * @param route The route of the bus.
         * @param busNumber The bus number.
         * @param capacity The capacity of the bus.
         * @return True if the bus was created successfully, false otherwise.
         */
        bool createBus(char state, std::string route, int busNumber, int capacity);

        /**
         * @brief Creates a taxi.
         * 
         * @param state The state where the taxi operates.
         * @param route The route of the taxi.
         * @param taxiCompany The company that owns the taxi.
         * @param taxiNumber The taxi number.
         * @return True if the taxi was created successfully, false otherwise.
         */
        bool createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber);

        /**
         * @brief Creates a passenger train.
         * 
         * @param state The state where the train operates.
         * @param line The line of the train.
         * @return True if the train was created successfully, false otherwise.
         */
        bool createPassengerTrain(char state, std::string line);

        /**
         * @brief Creates a freight train.
         * 
         * @param state The state where the train operates.
         * @param line The line of the train.
         * @param weight The weight of the freight.
         * @param length The length of the freight.
         * @return True if the train was created successfully, false otherwise.
         */
        bool createFreightTrain(char state, std::string line, float weight, float length);

        /**
         * @brief Creates a commercial airport.
         * 
         * @param state The state where the airport is located.
         * @param name The name of the airport.
         * @return True if the airport was created successfully, false otherwise.
         */
        bool createComercialAirport(char state, std::string name);

        /**
         * @brief Creates a cargo airport.
         * 
         * @param state The state where the airport is located.
         * @param name The name of the airport.
         * @return True if the airport was created successfully, false otherwise.
         */
        bool createCargoAirport(char state, std::string name);

        /**
         * @brief Gets a transportation object by index.
         * 
         * @param index The index of the transportation object.
         * @return A pointer to the transportation object.
         */
        Transportation* getTransportation(size_t index);

        /**
         * @brief Destructor for the TransportManager class.
         */
        ~TransportManager();
};

#endif // TRANSPORTMANAGER_H