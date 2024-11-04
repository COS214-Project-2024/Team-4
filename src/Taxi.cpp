/**
 * @file Taxi.cpp
 * @brief Implementation of the Taxi class.
 * 
 * This file contains the implementation of the Taxi class, which represents a taxi service in the public transit system.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "Taxi.h"

/**
 * @brief Constructor for Taxi.
 * 
 * Initializes the taxi with the given state, route, taxi company, and taxi number.
 * 
 * @param state The state of the taxi.
 * @param route The route of the taxi.
 * @param taxiCompany The company that owns the taxi.
 * @param taxiNumber The number of the taxi.
 */
Taxi::Taxi(char state, std::string route, std::string taxiCompany, int taxiNumber) : PublicTransit(state, route, 'T') {
    this->taxiCompany = taxiCompany;
    this->taxiNumber = taxiNumber;
}

/**
 * @brief Adds an inside road to the taxi's route.
 * 
 * @param insideRoad Pointer to the InsideRoad object.
 * @return True if the inside road was added, false if it was already present.
 */
bool Taxi::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds a commercial airport to the taxi's route.
 * 
 * @param comercialAirport Pointer to the ComercialAirport object.
 * @return True if the commercial airport was added, false if it was already present.
 */
bool Taxi::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }
    
    comercialAirports.push_back(comercialAirport);
    return true;
}

/**
 * @brief Adds a cargo airport to the taxi's route.
 * 
 * @param cargoAirport Pointer to the CargoAirport object.
 * @return True if the cargo airport was added, false if it was already present.
 */
bool Taxi::addCargoAirport(CargoAirport *cargoAirport) {
    for(CargoAirport *x : this->cargoAirports){
        if(x == cargoAirport){
            return false;
        }
    }
    
    cargoAirports.push_back(cargoAirport);
    return true;
}

/**
 * @brief Adds a passenger train to the taxi's route.
 * 
 * @param passengerTrain Pointer to the PassengerTrain object.
 * @return True if the passenger train was added, false if it was already present.
 */
bool Taxi::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }
    
    passengerTrains.push_back(passengerTrain);
    return true;
}

/**
 * @brief Adds a freight train to the taxi's route.
 * 
 * @param freightTrain Pointer to the FreightTrain object.
 * @return True if the freight train was added, false if it was already present.
 */
bool Taxi::addFreightTrain(FreightTrain *freightTrain) {
    for(FreightTrain *x : this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }
    
    freightTrains.push_back(freightTrain);
    return true;
}   

/**
 * @brief Adds a building to the taxi's route.
 * 
 * @param building Pointer to the Building object.
 * @return True if the building was added, false if it was already present.
 */
bool Taxi::addBuilding(Building *building) {
    for(Building *x : this->buildings){
        if(x == building){
            return false;
        }
    }
    
    buildings.push_back(building);
    return true;
}

/**
 * @brief Gets an inside road by index.
 * 
 * @param x The index of the inside road.
 * @return Pointer to the InsideRoad object, or nullptr if the index is out of range.
 */
InsideRoad *Taxi::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0){
        return insideRoads[x];
    }
    return nullptr;
}

/**
 * @brief Gets a commercial airport by index.
 * 
 * @param x The index of the commercial airport.
 * @return Pointer to the ComercialAirport object, or nullptr if the index is out of range.
 */
ComercialAirport *Taxi::getComercialAirport(std::size_t x) {
    if(x < comercialAirports.size() && x >= 0){
        return comercialAirports[x];
    }
    return nullptr;
}

/**
 * @brief Gets a cargo airport by index.
 * 
 * @param x The index of the cargo airport.
 * @return Pointer to the CargoAirport object, or nullptr if the index is out of range.
 */
CargoAirport *Taxi::getCargoAirport(std::size_t x) {
    if(x < cargoAirports.size() && x >= 0){
        return cargoAirports[x];
    }
    return nullptr;
}

/**
 * @brief Gets a passenger train by index.
 * 
 * @param x The index of the passenger train.
 * @return Pointer to the PassengerTrain object, or nullptr if the index is out of range.
 */
PassengerTrain *Taxi::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0){
        return passengerTrains[x];
    }
    return nullptr;
}

/**
 * @brief Gets a freight train by index.
 * 
 * @param x The index of the freight train.
 * @return Pointer to the FreightTrain object, or nullptr if the index is out of range.
 */
FreightTrain *Taxi::getFreightTrain(std::size_t x) {
    if(x < freightTrains.size() && x >= 0){
        return freightTrains[x];
    }
    return nullptr;
}

/**
 * @brief Gets a building by index.
 * 
 * @param x The index of the building.
 * @return Pointer to the Building object, or nullptr if the index is out of range.
 */
Building *Taxi::getBuilding(std::size_t x) {
    if(x < buildings.size() && x >= 0){
        return buildings[x];
    }
    return nullptr;
}

/**
 * @brief Gets the route name of the taxi.
 * 
 * @return The route name.
 */
std::string Taxi::getRouteName() {
    return this->getRoute();
}

/**
 * @brief Gets the taxi company name.
 * 
 * @return The taxi company name.
 */
std::string Taxi::getTaxiCompany() {
    return this->taxiCompany;
}

/**
 * @brief Gets the taxi number.
 * 
 * @return The taxi number.
 */
int Taxi::getTaxiNumber() {
    return this->taxiNumber;
}