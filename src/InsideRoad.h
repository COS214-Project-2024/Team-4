/**
 * @file InsideRoad.h
 * @brief Header file for the InsideRoad class.
 *
 * This file contains the declaration of the InsideRoad class, which represents a type of road
 * that can contain various transportation entities such as buses, taxis, airports, and trains.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef INSIDEROAD_H
#define INSIDEROAD_H

#include <vector>
#include <iostream>

#include "Road.h"
#include "Highway.h"
#include "Bus.h"
#include "Taxi.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "PassengerTrain.h"
#include "FreightTrain.h"
#include "Building.h"

class Highway;
class Bus;
class Taxi;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;
class Building;

/**
 * @class InsideRoad
 * @brief Represents an inside road that can contain various transportation entities.
 *
 * The InsideRoad class inherits from the Road class and adds functionality to manage
 * different types of transportation entities such as buses, taxis, airports, and trains.
 */
class InsideRoad : public Road {
    private:
        float avgStopTime; ///< Average stop time on this road.
        std::vector<InsideRoad*> insideRoads; ///< List of inside roads connected to this road.
        std::vector<Highway*> highways; ///< List of highways connected to this road.
        std::vector<Bus*> buses; ///< List of buses on this road.
        std::vector<Taxi*> taxis; ///< List of taxis on this road.
        std::vector<ComercialAirport*> comercialAirports; ///< List of commercial airports connected to this road.
        std::vector<CargoAirport*> cargoAirports; ///< List of cargo airports connected to this road.
        std::vector<PassengerTrain*> passengerTrains; ///< List of passenger trains connected to this road.
        std::vector<FreightTrain*> freightTrains; ///< List of freight trains connected to this road.
        std::vector<Building*> buildings; ///< List of buildings on this road.

    public:
        /**
         * @brief Constructor for the InsideRoad class.
         * @param state The state of the road.
         * @param roadName The name of the road.
         * @param avgStopTime The average stop time on this road.
         */
        InsideRoad(char state, std::string roadName, float avgStopTime);

        /**
         * @brief Adds an inside road to this road.
         * @param insideRoad Pointer to the inside road to be added.
         * @return True if the inside road was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a highway to this road.
         * @param highway Pointer to the highway to be added.
         * @return True if the highway was added successfully, false otherwise.
         */
        bool addHighway(Highway *highway);

        /**
         * @brief Adds a bus to this road.
         * @param bus Pointer to the bus to be added.
         * @return True if the bus was added successfully, false otherwise.
         */
        bool addBus(Bus *bus);

        /**
         * @brief Adds a taxi to this road.
         * @param taxi Pointer to the taxi to be added.
         * @return True if the taxi was added successfully, false otherwise.
         */
        bool addTaxi(Taxi *taxi);

        /**
         * @brief Adds a commercial airport to this road.
         * @param comercialAirport Pointer to the commercial airport to be added.
         * @return True if the commercial airport was added successfully, false otherwise.
         */
        bool addComercialAirport(ComercialAirport *comercialAirport);

        /**
         * @brief Adds a cargo airport to this road.
         * @param cargoAirport Pointer to the cargo airport to be added.
         * @return True if the cargo airport was added successfully, false otherwise.
         */
        bool addCargoAirport(CargoAirport *cargoAirport);

        /**
         * @brief Adds a passenger train to this road.
         * @param passengerTrain Pointer to the passenger train to be added.
         * @return True if the passenger train was added successfully, false otherwise.
         */
        bool addPassengerTrain(PassengerTrain *passengerTrain);

        /**
         * @brief Adds a freight train to this road.
         * @param freightTrain Pointer to the freight train to be added.
         * @return True if the freight train was added successfully, false otherwise.
         */
        bool addFreightTrain(FreightTrain *freightTrain);

        /**
         * @brief Gets a freight train from the list of freight trains.
         * @param x Index of the freight train to be retrieved.
         * @return Pointer to the freight train at the specified index.
         */
        FreightTrain* getFreightTrain(std::size_t x);

        /**
         * @brief Adds a building to the road.
         * 
         * This function adds a building to the road's list of buildings.
         * 
         * @param building Pointer to the building to be added.
         * @return true if the building was added successfully, false otherwise.
         */
        bool addBuilding(Building *building);

        /**
         * @brief Gets a passenger train from the list of passenger trains.
         * @param x Index of the passenger train to be retrieved.
         * @return Pointer to the passenger train at the specified index.
         */
        PassengerTrain* getPassengerTrain(std::size_t x);

        /**
         * @brief Gets a highway from the list of highways.
         * @param x Index of the highway to be retrieved.
         * @return Pointer to the highway at the specified index.
         */
        Highway* getHighway(std::size_t x);

        /**
         * @brief Gets an inside road from the list of inside roads.
         * @param x Index of the inside road to be retrieved.
         * @return Pointer to the inside road at the specified index.
         */
        InsideRoad* getInsideRoad(std::size_t x);

        /**
         * @brief Gets a bus from the list of buses.
         * @param x Index of the bus to be retrieved.
         * @return Pointer to the bus at the specified index.
         */
        Bus* getBus(std::size_t x);

        /**
         * @brief Gets a taxi from the list of taxis.
         * @param x Index of the taxi to be retrieved.
         * @return Pointer to the taxi at the specified index.
         */
        Taxi* getTaxi(std::size_t x);

        /**
         * @brief Gets a commercial airport from the list of commercial airports.
         * @param x Index of the commercial airport to be retrieved.
         * @return Pointer to the commercial airport at the specified index.
         */
        ComercialAirport* getComercialAirport(std::size_t x);

        /**
         * @brief Gets a cargo airport from the list of cargo airports.
         * @param x Index of the cargo airport to be retrieved.
         * @return Pointer to the cargo airport at the specified index.
         */
        CargoAirport* getCargoAirport(std::size_t x);

        /**
         * @brief Gets a building from the list of buildings.
         * @param x Index of the building to be retrieved.
         * @return Pointer to the building at the specified index.
         */
        Building *getBuilding(std::size_t x);

        /**
         * @brief Gets the average stop time on this road.
         * @return The average stop time.
         */
        float getAvgStopTime();

        /**
         * @brief Gets the name of this road.
         * @return The name of the road.
         */
        std::string getRoadName();

        /**
         * @brief Calculates the adjusted commute time.
         * 
         * This function computes the adjusted commute time based on various factors
         * such as traffic conditions, road quality, and other relevant parameters.
         * 
         * @return The adjusted commute time as a float.
         */
        float commuteTime() override;


};

#endif // INSIDEROAD_H