/**
 * @file CargoAirport.h
 * @brief Header file for the CargoAirport class.
 *
 * This file contains the definition of the CargoAirport class, which inherits from the Airport class.
 * The CargoAirport class manages a collection of InsideRoad and CargoAirport objects.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef CARGOAIRPORT_H
#define CARGOAIRPORT_H

#include "Airport.h"
#include "InsideRoad.h"

class InsideRoad;

/**
 * @class CargoAirport
 * @brief Represents a cargo airport.
 *
 * The CargoAirport class inherits from the Airport class and manages a collection of InsideRoad and CargoAirport objects.
 */
class CargoAirport : public Airport {
    private:
        std::vector<InsideRoad*> insideRoads; ///< Collection of inside roads associated with the cargo airport.
        std::vector<CargoAirport*> cargoAirports; ///< Collection of cargo airports associated with the cargo airport.

    public:
        /**
         * @brief Constructor for the CargoAirport class.
         * @param state The state of the cargo airport.
         * @param name The name of the cargo airport.
         */
        CargoAirport(char state, std::string name);

        /**
         * @brief Adds an inside road to the cargo airport.
         * @param insideRoad Pointer to the InsideRoad object to be added.
         * @return True if the inside road was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a cargo airport to the cargo airport.
         * @param cargoAirport Pointer to the CargoAirport object to be added.
         * @return True if the cargo airport was added successfully, false otherwise.
         */
        bool addCargoAirport(CargoAirport *cargoAirport);

        /**
         * @brief Gets an inside road by index.
         * @param index The index of the inside road to retrieve.
         * @return Pointer to the InsideRoad object at the specified index.
         */
        InsideRoad* getInsideRoad(std::size_t index);

        /**
         * @brief Gets a cargo airport by index.
         * @param index The index of the cargo airport to retrieve.
         * @return Pointer to the CargoAirport object at the specified index.
         */
        CargoAirport* getCargoAirport(std::size_t index);

        /**
         * @brief Gets the name of the cargo airport.
         * @return The name of the cargo airport.
         */
        std::string getName();

        /**
         * @brief Calculates the adjusted commute time.
         * 
         * This function computes the adjusted commute time based on various factors
         * such as traffic conditions, distance, and other relevant parameters.
         * 
         * @return The adjusted commute time as a float.
         */
        float commuteTime() override;
};

#endif