/**
 * @file Taxi.h
 * @brief Header file for the Taxi class, which represents a taxi in a public transit system.
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TAXI_H
#define TAXI_H

#include "PublicTransit.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"
#include "Building.h"

class InsideRoad;
class ComercialAirport;
class CargoAirport;
class PassengerTrain;
class FreightTrain;
class Building;

/**
 * @class Taxi
 * @brief A class representing a taxi in a public transit system.
 */
class Taxi : public PublicTransit {
    private:
        std::string taxiCompany; ///< The company that owns the taxi.
        int taxiNumber; ///< The unique number identifying the taxi.

        std::vector<InsideRoad*> insideRoads; ///< List of inside roads the taxi can access.
        std::vector<ComercialAirport*> comercialAirports; ///< List of commercial airports the taxi can access.
        std::vector<CargoAirport*> cargoAirports; ///< List of cargo airports the taxi can access.
        std::vector<PassengerTrain*> passengerTrains; ///< List of passenger trains the taxi can access.
        std::vector<FreightTrain*> freightTrains; ///< List of freight trains the taxi can access.
        std::vector<Building*> buildings; ///< List of buildings the taxi can access.

    public:
        /**
         * @brief Constructor for the Taxi class.
         * @param state The state of the taxi.
         * @param route The route of the taxi.
         * @param taxiCompany The company that owns the taxi.
         * @param taxiNumber The unique number identifying the taxi.
         */
        Taxi(char state, std::string route, std::string taxiCompany, int taxiNumber);

        /**
         * @brief Adds an inside road to the taxi's accessible roads.
         * @param insideRoad Pointer to the InsideRoad object.
         * @return True if the road was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a commercial airport to the taxi's accessible airports.
         * @param comercialAirport Pointer to the ComercialAirport object.
         * @return True if the airport was added successfully, false otherwise.
         */
        bool addComercialAirport(ComercialAirport *comercialAirport);

        /**
         * @brief Adds a cargo airport to the taxi's accessible airports.
         * @param cargoAirport Pointer to the CargoAirport object.
         * @return True if the airport was added successfully, false otherwise.
         */
        bool addCargoAirport(CargoAirport *cargoAirport);

        /**
         * @brief Adds a passenger train to the taxi's accessible trains.
         * @param passengerTrain Pointer to the PassengerTrain object.
         * @return True if the train was added successfully, false otherwise.
         */
        bool addPassengerTrain(PassengerTrain *passengerTrain);

        /**
         * @brief Adds a freight train to the taxi's accessible trains.
         * @param freightTrain Pointer to the FreightTrain object.
         * @return True if the train was added successfully, false otherwise.
         */
        bool addFreightTrain(FreightTrain *freightTrain);

        /**
         * @brief Adds a building to the taxi's accessible buildings.
         * @param building Pointer to the Building object.
         * @return True if the building was added successfully, false otherwise.
         */
        bool addBuilding(Building *building);

        /**
         * @brief Gets an inside road from the taxi's accessible roads.
         * @param x The index of the inside road.
         * @return Pointer to the InsideRoad object.
         */
        InsideRoad *getInsideRoad(std::size_t x);

        /**
         * @brief Gets a commercial airport from the taxi's accessible airports.
         * @param x The index of the commercial airport.
         * @return Pointer to the ComercialAirport object.
         */
        ComercialAirport *getComercialAirport(std::size_t x);

        /**
         * @brief Gets a cargo airport from the taxi's accessible airports.
         * @param x The index of the cargo airport.
         * @return Pointer to the CargoAirport object.
         */
        CargoAirport *getCargoAirport(std::size_t x);

        /**
         * @brief Gets a passenger train from the taxi's accessible trains.
         * @param x The index of the passenger train.
         * @return Pointer to the PassengerTrain object.
         */
        PassengerTrain *getPassengerTrain(std::size_t x);

        /**
         * @brief Gets a freight train from the taxi's accessible trains.
         * @param x The index of the freight train.
         * @return Pointer to the FreightTrain object.
         */
        FreightTrain *getFreightTrain(std::size_t x);

        /**
         * @brief Gets a building from the taxi's accessible buildings.
         * @param x The index of the building.
         * @return Pointer to the Building object.
         */
        Building *getBuilding(std::size_t x);

        /**
         * @brief Gets the route name of the taxi.
         * @return The route name.
         */
        std::string getRouteName();

        /**
         * @brief Gets the company that owns the taxi.
         * @return The taxi company name.
         */
        std::string getTaxiCompany();

        /**
         * @brief Gets the unique number identifying the taxi.
         * @return The taxi number.
         */
        int getTaxiNumber();

        /**
         * @brief Calculates the adjusted commute time.
         * 
         * This function computes the adjusted commute time based on various factors
         * such as traffic conditions, distance, and other relevant parameters.
         * 
         * @return The adjusted commute time as a float.
         */
        float commuteTime();
};

#endif