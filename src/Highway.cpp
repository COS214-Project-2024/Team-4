#include "Highway.h"

Highway::Highway(char state, std::string roadName, float speedLimit) : Road(state, roadName) {
    this->speedLimit = speedLimit;
}

bool Highway::addInsideRoad(InsideRoad *insideRoad) {
    for(InsideRoad *x: this->insideRoads){
        if(x == insideRoad){
            return false;
        }
    
    }

    this->insideRoads.push_back(insideRoad);
    return true;
}

bool Highway::addHighway(Highway *highway) {
    for(Highway *x: this->highways){
        if(x == highway){
            return false;
        }
    
    }

    this->highways.push_back(highway);
    return true;
}


std::string Highway::getRoadName() {
    return this->getRoadName();
}

InsideRoad *Highway::getInsideRoad(std::size_t x) {
    if(x < this->insideRoads.size() && x >= 0){
        return this->insideRoads[x];
    }else return nullptr;

} 

Highway *Highway::getHighway(std::size_t x) {
    if(x < this->highways.size() && x >= 0){
        return this->highways[x];
    }else return nullptr;

}

float Highway::getSpeedLimit() {
    return this->speedLimit;
}