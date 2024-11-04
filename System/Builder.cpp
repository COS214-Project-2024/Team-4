#include "Builder.h"
//base class for all builders

//sets name of the building
Builder& Builder::setName(string name) {
    this->name = name;
    return *this;
}

//sets area of the building
Builder& Builder::setArea(float area) {
    this->area = area;
    return *this;
}

//sets number of floors in the building
Builder& Builder::setFloors(int floors) {
    this->floors = floors;
    return *this;
}

//sets capacity of the building
Builder& Builder::setCapacity(int capacity) {
    this->capacity = capacity;
    return *this;
}

//sets citizen satisfaction of the building
Builder& Builder::setCitizenSatisfaction(float citizenSatisfaction) {
    this->citizenSatisfaction = citizenSatisfaction;
    return *this;
}

//sets economic growth of the building
Builder& Builder::setEconomicGrowth(float economicGrowth) {
    this->economicGrowth = economicGrowth;
    return *this;
}

//sets resource consumption of the building
Builder& Builder::setResourceConsumption(float resourceConsumption) {
    this->resourceConsumption = resourceConsumption;
    return *this;
}

