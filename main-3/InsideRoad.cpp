#include "InsideRoad.h"

InsideRoad::InsideRoad(char state, std::string roadName, float avgStopTime) : Road(state, roadName, 'I') {
    this->avgStopTime = avgStopTime;
}

std::string InsideRoad::getRoadName() {
    return this->getName();
}

bool InsideRoad::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x : this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }

    this->insideRoads.push_back(insideRoad);
    return true;
}

bool InsideRoad::addHighway(Highway *highway){
    for(Highway *x : this->highways){
        if(x == highway){
            return false;
        }
    }

    this->highways.push_back(highway);
    return true;
}

bool InsideRoad::addBus(Bus *bus){
    for(Bus *x : this->buses){
        if(x == bus){
            return false;
        }
    }

    this->buses.push_back(bus);
    return true;
}

bool InsideRoad::addTaxi(Taxi *taxi){
    for(Taxi *x : this->taxis){
        if(x == taxi){
            return false;
        }
    }

    this->taxis.push_back(taxi);
    return true;
}

bool InsideRoad::addCargoAirport(CargoAirport *cargoAirport){
    for(CargoAirport *x : this->cargoAirports){
        if(x == cargoAirport){
            return false;
        }
    }

    this->cargoAirports.push_back(cargoAirport);
    return true;
}


bool InsideRoad::addComercialAirport(ComercialAirport *comercialAirport){
    for(ComercialAirport *x : this->comercialAirports){
        if(x == comercialAirport){
            return false;
        }
    }

    this->comercialAirports.push_back(comercialAirport);
    return true;

}   

bool InsideRoad::addPassengerTrain(PassengerTrain *passengerTrain){
    for(PassengerTrain *x : this->passengerTrains){
        if(x == passengerTrain){
            return false;
        }
    }

    this->passengerTrains.push_back(passengerTrain);
    return true;
}

bool InsideRoad::addFreightTrain(FreightTrain *freightTrain){
    for(FreightTrain *x : this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }

    this->freightTrains.push_back(freightTrain);
    return true;
}

bool InsideRoad::addBuilding(Building *building){
    for(Building *x : this->buildings){
        if(x == building){
            return false;
        }
    }

    this->buildings.push_back(building);
    return true;
}

Highway *InsideRoad::getHighway(std::size_t x){
    if(x < this->highways.size() && x >= 0){
        return this->highways[x];
    }else return nullptr;
}

InsideRoad *InsideRoad::getInsideRoad(std::size_t x){
    if(x < this->insideRoads.size() && x >= 0){
        return this->insideRoads[x];
    }else return nullptr;
}

Bus *InsideRoad::getBus(std::size_t x){
    if(x < this->buses.size() && x >= 0){
        return this->buses[x];
    }else return nullptr;
}

Taxi *InsideRoad::getTaxi(std::size_t x){
    if(x < this->taxis.size() && x >= 0){
        return this->taxis[x];
    }else return nullptr;
}

ComercialAirport *InsideRoad::getComercialAirport(std::size_t x){
    if(x < this->comercialAirports.size() && x >= 0){
        return this->comercialAirports[x];
    }else return nullptr;
}

CargoAirport *InsideRoad::getCargoAirport(std::size_t x){
    if(x < this->cargoAirports.size() && x >= 0){
        return this->cargoAirports[x];
    }else return nullptr;
}

PassengerTrain *InsideRoad::getPassengerTrain(std::size_t x){
    if(x < this->passengerTrains.size() && x >= 0){
        return this->passengerTrains[x];
    }else return nullptr;
}

FreightTrain *InsideRoad::getFreightTrain(std::size_t x){
    if(x < this->freightTrains.size() && x >= 0){
        return this->freightTrains[x];
    }else return nullptr;
}

Building *InsideRoad::getBuilding(std::size_t x){
    if(x < this->buildings.size() && x >= 0){
        return this->buildings[x];
    }else return nullptr;
}

// std::vector<Building*> InsideRoad::getBuildingsList(){
//     return this->buildings;
// }

float InsideRoad::getAvgStopTime(){
    return this->avgStopTime;
}

float InsideRoad::commuteTime(){
    return this->calculateCommute() + this->avgStopTime;
}