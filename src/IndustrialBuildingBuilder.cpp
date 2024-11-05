#include "IndustrialBuildingBuilder.h"

//sets pollution level of the building
IndustrialBuildingBuilder& IndustrialBuildingBuilder::setPollutionLevel(float level) {
    this->pollutionLevel = level;
    return *this;
}

//sets production capacity of the building
IndustrialBuildingBuilder& IndustrialBuildingBuilder::setProductionCapacity(float capacity) {
    this->productionCapacity = capacity;
    return *this;
}

//gets pollution level of the building
float IndustrialBuildingBuilder::getPollutionLevel() {
	return this->pollutionLevel;
}

//gets production capacity of the building
float IndustrialBuildingBuilder::getProductionCapacity() {
	return this->productionCapacity;
}

//builds the industrial building,sets all the attributes of the building
std::unique_ptr<Building> IndustrialBuildingBuilder::build() {
    return std::make_unique<IndustrialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, productionCapacity, pollutionLevel
    );
}

IndustrialBuildingBuilder::IndustrialBuildingBuilder() {
    // will add something
}
