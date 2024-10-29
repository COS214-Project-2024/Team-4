#include "LandmarkBuildingBuilder.h"

int LandmarkBuildingBuilder::getVisitorCapacity() {
	return this->visitorCapacity;
}

LandmarkBuildingBuilder& LandmarkBuildingBuilder::setVisitorCapacity(int visitorCapacity) {
    this->visitorCapacity = visitorCapacity;
    return *this;
}


float LandmarkBuildingBuilder::getCulturalValue() {
	return this->culturalValue;
}

LandmarkBuildingBuilder& LandmarkBuildingBuilder::setCulturalValue(float culturalValue) {
    this->culturalValue = culturalValue;
    return *this;
}

bool LandmarkBuildingBuilder::getIsHistoric() {
	return this->isHistoric;
}

LandmarkBuildingBuilder& LandmarkBuildingBuilder::setIsHistoric(bool isHistoric) {
    this->isHistoric = isHistoric;
    return *this;
}

std::unique_ptr<Building> LandmarkBuildingBuilder::build() {
    return std::make_unique<LandmarkBuilding>(
        name, area, floors, capacity, citizenSatisfaction,
        economicGrowth, resourceConsumption, visitorCapacity, culturalValue, isHistoric
    );
}
