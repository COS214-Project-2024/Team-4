/**
 * @file ComercialAirport.h
 * @brief Defines the ComercialAirport class which inherits from the Airport class.
 * 
 * This file contains the declaration of the ComercialAirport class, which represents
 * a commercial airport. It includes methods to manage roads and other commercial airports
 * associated with this airport.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef COMERCIALAIRPORT_H
#define COMERCIALAIRPORT_H

#include "Airport.h"
#include "InsideRoad.h"

class InsideRoad;

/**
 * @class ComercialAirport
 * @brief Represents a commercial airport.
 * 
 * The ComercialAirport class inherits from the Airport class and provides additional
 * functionality specific to commercial airports, such as connecting roads and other
 * commercial airports.
 */
class ComercialAirport : public Airport {
    private:
        std::vector<InsideRoad*> roads; ///< Vector of pointers to InsideRoad objects.
        std::vector<ComercialAirport*> comercialAirports; ///< Vector of pointers to ComercialAirport objects.

    public:
        /**
         * @brief Constructor for ComercialAirport.
         * 
         * @param state The state of the airport.
         * @param name The name of the airport.
         */
        ComercialAirport(char state, std::string name);

        /**
         * @brief Adds a road to the airport.
         * 
         * @param road Pointer to the InsideRoad object to be added.
         * @return true if the road was added successfully, false otherwise.
         */
        bool addRoad(InsideRoad *road);

        /**
         * @brief Adds a commercial airport to the list.
         * 
         * @param comercialAirport Pointer to the ComercialAirport object to be added.
         * @return true if the commercial airport was added successfully, false otherwise.
         */
        bool addComercialAirport(ComercialAirport *comercialAirport);

        /**
         * @brief Gets a road by index.
         * 
         * @param index The index of the road to retrieve.
         * @return Pointer to the InsideRoad object at the specified index.
         */
        InsideRoad* getRoad(std::size_t index);

        /**
         * @brief Gets a commercial airport by index.
         * 
         * @param index The index of the commercial airport to retrieve.
         * @return Pointer to the ComercialAirport object at the specified index.
         */
        ComercialAirport* getComercialAirport(std::size_t index);

        /**
         * @brief Gets the name of the airport.
         * 
         * @return The name of the airport.
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
        float commuteTime();

};

#endif