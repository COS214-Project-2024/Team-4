/**
 * @file InsideRoad.cpp
 * @brief Implementation of the InsideRoad class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the implementation of the InsideRoad class, which represents an inside road
 * with specific attributes and behaviors.
 */

#include "InsideRoad.h"

/**
 * @brief Constructor for InsideRoad.
 * @param state The state of the inside road.
 * @param roadName The name of the inside road.
 * @param avgStopTime The average stop time on the inside road.
 */
InsideRoad::InsideRoad(char state, std::string roadName, float avgStopTime) : Road(state, roadName, 'I') {
    this->avgStopTime = avgStopTime;
}

/**
 * @brief Gets the name of the inside road.
 * @return The name of the inside road.
 */
std::string InsideRoad::getRoadName() {
    return this->getName();
}

/**
 * @brief Adds an InsideRoad to the inside road.
 * @param insideRoad Pointer to the InsideRoad to be added.
 * @return True if the InsideRoad was added successfully, false if it already exists.
 */
bool InsideRoad::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }

    this->insideRoads.push_back(insideRoad);
    return true;
}

/**
 * @brief Adds a Highway to the inside road.
 * @param highway Pointer to the Highway to be added.
 * @return True if the Highway was added successfully, false if it already exists.
 */
bool InsideRoad::addHighway(Highway *highway){
    for(Highway *x : this->highways){
        if(x == highway){
            return false;
        }
    }

    this->highways.push_back(highway);
    return true;
}

/**
 * @brief Adds a Bus to the inside road.
 * @param bus Pointer to the Bus to be added.
 * @return True if the Bus was added successfully, false if it already exists.
 */
bool InsideRoad::addBus(Bus *bus){
    for(Bus *x : this->buses){
        if(x == bus){
            return false;
        }
    }

    this->buses.push_back(bus);
    return true;
}

/**
 * @brief Adds a Taxi to the inside road.
 * @param taxi Pointer to the Taxi to be added.
 * @return True if the Taxi was added successfully, false if it already exists.
 */
bool InsideRoad::addTaxi(Taxi *taxi){
    for(Taxi *x : this->taxis){
        if(x == taxi){
            return false;
        }
    }

    this->taxis.push_back(taxi);
    return true;
}

/**
 * @brief Adds a CargoAirport to the inside road.
 * @param cargoAirport Pointer to the CargoAirport to be added.
 * @return True if the CargoAirport was added successfully, false if it already exists.
 */
bool InsideRoad::addCargoAirport(CargoAirport *cargoAirport){
    for(CargoAirport *x : this->cargoAirports){
        if(x == cargoAirport){
            return false;
        }
    }

    this->cargoAirports.push_back(cargoAirport);
    return true;
}

/**
 * @brief Adds a ComercialAirport to the inside road.
 * @param comercialAirport Pointer to the ComercialAirport to be added.
 * @return True if the ComercialAirport was added successfully, false if it already exists.
 */
bool InsideRoad::addComercialAirport(ComercialAirport *comercialAirport){
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }

    this->comercialAirports.push_back(comercialAirport);
    return true;
}   

/**
 * @brief Adds a PassengerTrain to the inside road.
 * @param passengerTrain Pointer to the PassengerTrain to be added.
 * @return True if the PassengerTrain was added successfully, false if it already exists.
 */
bool InsideRoad::addPassengerTrain(PassengerTrain *passengerTrain){
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }

    this->passengerTrains.push_back(passengerTrain);
    return true;
}

/**
 * @brief Adds a FreightTrain to the inside road.
 * @param freightTrain Pointer to the FreightTrain to be added.
 * @return True if the FreightTrain was added successfully, false if it already exists.
 */
bool InsideRoad::addFreightTrain(FreightTrain *freightTrain){
    for(FreightTrain *x : this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }

    this->freightTrains.push_back(freightTrain);
    return true;
}

/**
 * @brief Adds a Building to the inside road.
 * @param building Pointer to the Building to be added.
 * @return True if the Building was added successfully, false if it already exists.
 */
bool InsideRoad::addBuilding(Building *building){
    for(Building *x : this->buildings){
        if(x == building){
            return false;
        }
    }

    this->buildings.push_back(building);
    return true;
}

/**
 * @brief Gets a Highway by index.
 * @param x The index of the Highway.
 * @return Pointer to the Highway if the index is valid, nullptr otherwise.
 */
Highway *InsideRoad::getHighway(std::size_t x){
    if(x < this->highways.size() && x >= 0){
        return this->highways[x];
    }else return nullptr;
}

/**
 * @brief Gets an InsideRoad by index.
 * @param x The index of the InsideRoad.
 * @return Pointer to the InsideRoad if the index is valid, nullptr otherwise.
 */
InsideRoad *InsideRoad::getInsideRoad(std::size_t x){
    if(x < this->insideRoads.size() && x >= 0){
        return this->insideRoads[x];
    }else return nullptr;
}

/**
 * @brief Gets a Bus by index.
 * @param x The index of the Bus.
 * @return Pointer to the Bus if the index is valid, nullptr otherwise.
 */
Bus *InsideRoad::getBus(std::size_t x){
    if(x < this->buses.size() && x >= 0){
        return this->buses[x];
    }else return nullptr;
}

/**
 * @brief Gets a Taxi by index.
 * @param x The index of the Taxi.
 * @return Pointer to the Taxi if the index is valid, nullptr otherwise.
 */
Taxi *InsideRoad::getTaxi(std::size_t x){
    if(x < this->taxis.size() && x >= 0){
        return this->taxis[x];
    }else return nullptr;
}

/**
 * @brief Gets a ComercialAirport by index.
 * @param x The index of the ComercialAirport.
 * @return Pointer to the ComercialAirport if the index is valid, nullptr otherwise.
 */
ComercialAirport *InsideRoad::getComercialAirport(std::size_t x){
    if(x < this->comercialAirports.size() && x >= 0){
        return this->comercialAirports[x];
    }else return nullptr;
}

/**
 * @brief Gets a CargoAirport by index.
 * @param x The index of the CargoAirport.
 * @return Pointer to the CargoAirport if the index is valid, nullptr otherwise.
 */
CargoAirport *InsideRoad::getCargoAirport(std::size_t x){
    if(x < this->cargoAirports.size() && x >= 0){
        return this->cargoAirports[x];
    }else return nullptr;
}

/**
 * @brief Gets a PassengerTrain by index.
 * @param x The index of the PassengerTrain.
 * @return Pointer to the PassengerTrain if the index is valid, nullptr otherwise.
 */
PassengerTrain *InsideRoad::getPassengerTrain(std::size_t x){
    if(x < this->passengerTrains.size() && x >= 0){
        return this->passengerTrains[x];
    }else return nullptr;
}

/**
 * @brief Gets a FreightTrain by index.
 * @param x The index of the FreightTrain.
 * @return Pointer to the FreightTrain if the index is valid, nullptr otherwise.
 */
FreightTrain *InsideRoad::getFreightTrain(std::size_t x){
    if(x < this->freightTrains.size() && x >= 0){
        return this->freightTrains[x];
    }else return nullptr;
}

/**
 * @brief Gets a Building by index.
 * @param x The index of the Building.
 * @return Pointer to the Building if the index is valid, nullptr otherwise.
 */
Building *InsideRoad::getBuilding(std::size_t x){
    if(x < this->buildings.size() && x >= 0){
        return this->buildings[x];
    }else return nullptr;
}

/**
 * @brief Gets the average stop time on the inside road.
 * @return The average stop time.
 */
float InsideRoad::getAvgStopTime(){
    return this->avgStopTime;
}