#include "LandmarkBuildingBuilder.h"

int LandmarkBuildingBuilder::getVisitorCapacity() {
	return this->visitorCapacity;
}

void LandmarkBuildingBuilder::setVisitorCapacity(int visitorCapacity) {
	this->visitorCapacity = visitorCapacity;
}

float LandmarkBuildingBuilder::getCulturalValue() {
	return this->culturalValue;
}

void LandmarkBuildingBuilder::setCulturalValue(float culturalValue) {
	this->culturalValue = culturalValue;
}

bool LandmarkBuildingBuilder::getIsHistoric() {
	return this->isHistoric;
}

void LandmarkBuildingBuilder::setIsHistoric(bool isHistoric) {
	this->isHistoric = isHistoric;
}

LandmarkBuilding LandmarkBuildingBuilder::build() {
	// TODO - implement LandmarkBuildingBuilder::build
	throw "Not yet implemented";
}
