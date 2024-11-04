/**
 * @file TransportationFactory.cpp
 * @brief Implementation of the TransportationFactory class.
 * 
 * This file contains the implementation of the TransportationFactory class, which provides 
 * factory methods to create various types of transportation objects.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "TransportationFactory.h"

/**
 * @brief Creates a Highway object.
 * 
 * @param state The state of the highway (P for Peak, N for NonPeak, L for LunchRush).
 * @param roadName The name of the road.
 * @param speedLimit The speed limit of the highway.
 * @return A pointer to the created Highway object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createHighway(char state, std::string roadName, float speedLimit) {
    if (speedLimit < 100) {
        return nullptr;
    }

    if (roadName == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new Highway(state, roadName, speedLimit);
}

/**
 * @brief Creates an InsideRoad object.
 * 
 * @param state The state of the inside road (P for Peak, N for NonPeak, L for LunchRush).
 * @param roadName The name of the road.
 * @param avgStopTime The average stop time on the inside road.
 * @return A pointer to the created InsideRoad object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createInsideRoad(char state, std::string roadName, float avgStopTime) {
    if (avgStopTime <= 0) {
        return nullptr;
    }

    if (roadName == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new InsideRoad(state, roadName, avgStopTime);
}

/**
 * @brief Creates a Bus object.
 * 
 * @param state The state of the bus (P for Peak, N for NonPeak, L for LunchRush).
 * @param route The route of the bus.
 * @param busNumber The bus number.
 * @param capacity The capacity of the bus.
 * @return A pointer to the created Bus object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createBus(char state, std::string route, int busNumber, int capacity) {
    if (busNumber <= 0 || capacity <= 0) {
        return nullptr;
    }
    
    if (route == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new Bus(state, route, busNumber, capacity);
}

/**
 * @brief Creates a Taxi object.
 * 
 * @param state The state of the taxi (P for Peak, N for NonPeak, L for LunchRush).
 * @param route The route of the taxi.
 * @param taxiCompany The taxi company.
 * @param taxiNumber The taxi number.
 * @return A pointer to the created Taxi object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createTaxi(char state, std::string route, std::string taxiCompany, int taxiNumber) {
    if (taxiNumber <= 0) {
        return nullptr;
    }
    
    if (route == "" || taxiCompany == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new Taxi(state, route, taxiCompany, taxiNumber);
}

/**
 * @brief Creates a PassengerTrain object.
 * 
 * @param state The state of the passenger train (P for Peak, N for NonPeak, L for LunchRush).
 * @param line The line on which the passenger train operates.
 * @return A pointer to the created PassengerTrain object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createPassengerTrain(char state, std::string line) {
    if (line == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new PassengerTrain(state, line);
}

/**
 * @brief Creates a FreightTrain object.
 * 
 * @param state The state of the freight train (P for Peak, N for NonPeak, L for LunchRush).
 * @param line The line on which the freight train operates.
 * @param weight The weight of the freight train.
 * @param length The length of the freight train.
 * @return A pointer to the created FreightTrain object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createFreightTrain(char state, std::string line, float weight, float length) {
    if (weight <= 0 || length <= 0) {
        return nullptr;
    }
    
    if (line == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new FreightTrain(state, line, weight, length);
}

/**
 * @brief Creates a ComercialAirport object.
 * 
 * @param state The state of the commercial airport (P for Peak, N for NonPeak, L for LunchRush).
 * @param name The name of the commercial airport.
 * @return A pointer to the created ComercialAirport object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createComercialAirport(char state, std::string name) {
    if (name == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new ComercialAirport(state, name);
}

/**
 * @brief Creates a CargoAirport object.
 * 
 * @param state The state of the cargo airport (P for Peak, N for NonPeak, L for LunchRush).
 * @param name The name of the cargo airport.
 * @return A pointer to the created CargoAirport object, or nullptr if the parameters are invalid.
 */
Transportation* TransportationFactory::createCargoAirport(char state, std::string name) {
    if (name == "") {
        return nullptr;
    }

    if (state != 'P' && state != 'N' && state != 'L') {
        return nullptr;
    }

    return new CargoAirport(state, name);
}