#include "LandmarkBuildingBuilder.h"

//sets visitor capacity of the building
int LandmarkBuildingBuilder::getVisitorCapacity() {
	return this->visitorCapacity;
}

//sets visitor capacity of the building
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setVisitorCapacity(int visitorCapacity) {
    this->visitorCapacity = visitorCapacity;
    return *this;
}

//sets cultural value of the building
float LandmarkBuildingBuilder::getCulturalValue() {
	return this->culturalValue;
}

//sets cultural value of the building
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setCulturalValue(float culturalValue) {
    this->culturalValue = culturalValue;
    return *this;
}

//gets if the building is historic
bool LandmarkBuildingBuilder::getIsHistoric() {
	return this->isHistoric;
}

//sets if the building is historic
LandmarkBuildingBuilder& LandmarkBuildingBuilder::setIsHistoric(bool isHistoric) {
    this->isHistoric = isHistoric;
    return *this;
}

//builds the landmark building,sets all the attributes of the building
std::unique_ptr<Building> LandmarkBuildingBuilder::build() {
    return std::make_unique<LandmarkBuilding>(
        name, area, floors, capacity, citizenSatisfaction,
        economicGrowth, resourceConsumption, visitorCapacity, culturalValue, isHistoric
    );
}

LandmarkBuildingBuilder::LandmarkBuildingBuilder() {
    // will add something
}
