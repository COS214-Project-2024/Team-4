/**
 * @file Bus.h
 * @brief Header file for the Bus class.
 *
 * This file contains the declaration of the Bus class, which is a type of PublicTransit.
 * The Bus class manages information about buses, including their number, capacity, and
 * connections to other transportation modes such as InsideRoad, ComercialAirport, and PassengerTrain.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef BUS_H
#define BUS_H

#include <vector>

#include "PublicTransit.h"
#include "InsideRoad.h"
#include "ComercialAirport.h"
#include "PassengerTrain.h"

class InsideRoad;
class ComercialAirport;
class PassengerTrain;

/**
 * @class Bus
 * @brief Represents a bus in the public transit system.
 *
 * The Bus class inherits from PublicTransit and includes additional attributes
 * and methods specific to buses, such as bus number, capacity, and connections
 * to other transportation modes.
 */
class Bus : public PublicTransit {
    private:
        int busNumber; ///< The bus number.
        int capacity; ///< The capacity of the bus.
        std::vector<InsideRoad*> insideRoads; ///< List of InsideRoad connections.
        std::vector<Bus*> buses; ///< List of Bus connections.
        std::vector<ComercialAirport*> comercialAirports; ///< List of ComercialAirport connections.
        std::vector<PassengerTrain*> passengerTrains; ///< List of PassengerTrain connections.

    public:
        /**
         * @brief Constructs a Bus object.
         * @param state The state of the bus.
         * @param route The route name of the bus.
         * @param busNumber The bus number.
         * @param capacity The capacity of the bus.
         */
        Bus(char state, std::string route, int busNumber, int capacity);

        /**
         * @brief Adds an InsideRoad connection to the bus.
         * @param insideRoad Pointer to the InsideRoad object.
         * @return True if the InsideRoad was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a Bus connection to the bus.
         * @param bus Pointer to the Bus object.
         * @return True if the Bus was added successfully, false otherwise.
         */
        bool addBus(Bus *bus);

        /**
         * @brief Adds a ComercialAirport connection to the bus.
         * @param comercialAirport Pointer to the ComercialAirport object.
         * @return True if the ComercialAirport was added successfully, false otherwise.
         */
        bool addComercialAirport(ComercialAirport *comercialAirport);

        /**
         * @brief Adds a PassengerTrain connection to the bus.
         * @param passengerTrain Pointer to the PassengerTrain object.
         * @return True if the PassengerTrain was added successfully, false otherwise.
         */
        bool addPassengerTrain(PassengerTrain *passengerTrain);

        /**
         * @brief Gets an InsideRoad connection by index.
         * @param x The index of the InsideRoad.
         * @return Pointer to the InsideRoad object.
         */
        InsideRoad *getInsideRoad(std::size_t x);

        /**
         * @brief Gets a Bus connection by index.
         * @param x The index of the Bus.
         * @return Pointer to the Bus object.
         */
        Bus *getBus(std::size_t x);

        /**
         * @brief Gets a ComercialAirport connection by index.
         * @param x The index of the ComercialAirport.
         * @return Pointer to the ComercialAirport object.
         */
        ComercialAirport *getComercialAirport(std::size_t x);

        /**
         * @brief Gets a PassengerTrain connection by index.
         * @param x The index of the PassengerTrain.
         * @return Pointer to the PassengerTrain object.
         */
        PassengerTrain *getPassengerTrain(std::size_t x);

        /**
         * @brief Gets the bus number.
         * @return The bus number.
         */
        int getBusNumber();

        /**
         * @brief Gets the capacity of the bus.
         * @return The capacity of the bus.
         */
        int getCapacity();

        /**
         * @brief Gets the route name of the bus.
         * @return The route name of the bus.
         */
        std::string getRouteName();

        /**
         * @brief Calculates the adjusted commute time.
         * 
         * This function computes the adjusted commute time based on various factors
         * such as traffic conditions, route changes, and other relevant parameters.
         * 
         * @return The adjusted commute time as a float.
         */
        float commuteTime();
};

#endif // BUS_H