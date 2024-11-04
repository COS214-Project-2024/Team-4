#include "FreightTrain.h"

FreightTrain::FreightTrain(char state, std::string line, float weight, float length) : Train(state, line, 'F') {
    this->weight = weight;
    this->length = length;
}

bool FreightTrain::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    }
    
    insideRoads.push_back(insideRoad);
    return true;
}

bool FreightTrain::addFreightTrain(FreightTrain *freightTrain) {
    for(FreightTrain *x: this->freightTrains){
        if(x == freightTrain){
            return false;
        }
    }
    
    freightTrains.push_back(freightTrain);
    return true;
}

InsideRoad *FreightTrain::getInsideRoad(size_t index){
    if(index < insideRoads.size() && index >= 0){
        return insideRoads[index];
    }
    return nullptr;
}

FreightTrain *FreightTrain::getFreightTrain(size_t index){
    if(index < freightTrains.size() && index >= 0){
        return freightTrains[index];
    }
    return nullptr;
}

float FreightTrain::getWeight(){
    return weight;
}

float FreightTrain::getLength(){
    return length;
}

std::string FreightTrain::getTrainLine(){
    return this->getLine();
}

float FreightTrain::commuteTime(){
    return this->commuteTime() * (1+weight/1000+length/100);    
    
}