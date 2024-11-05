#include "PassengerTrain.h"

PassengerTrain::PassengerTrain(char state, std::string line) : Train(state, line, 'P') {}

bool PassengerTrain::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads) {
        if(x == insideRoad) {
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

bool PassengerTrain::addPassengerTrain(PassengerTrain *passengerTrain) {
    for(PassengerTrain *x: this->passengerTrains) {
        if(x == passengerTrain) {
            return false;
        }
    }
    
    passengerTrains.push_back(passengerTrain);
    return true;
}

InsideRoad *PassengerTrain::getInsideRoad(std::size_t x) {
    if(x < insideRoads.size() && x >= 0) {
        return insideRoads[x];
    }
    
    return nullptr;
}

PassengerTrain *PassengerTrain::getPassengerTrain(std::size_t x) {
    if(x < passengerTrains.size() && x >= 0) {
        return passengerTrains[x];
    }
    
    return nullptr;
}

std::string PassengerTrain::getTrainLine() {
    return this->getLine();    
}

float PassengerTrain::commuteTime() {
    return this->calculateCommute();
}