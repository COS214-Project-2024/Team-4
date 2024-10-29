#include "IndustrialBuildingBuilder.h"

void IndustrialBuildingBuilder::setPollutionLevel(float pollutionLevel) {
	this->pollutionLevel = pollutionLevel;
}

void IndustrialBuildingBuilder::setProductionCapacity(float productionCapacity) {
	this->productionCapacity = productionCapacity;
}

float IndustrialBuildingBuilder::getPollutionLevel() {
	return this->pollutionLevel;
}

float IndustrialBuildingBuilder::getProductionCapacity() {
	return this->productionCapacity;
}

IndustrialBuilding IndustrialBuildingBuilder::build() {
	// TODO - implement IndustrialBuildingBuilder::build
	throw "Not yet implemented";
}
