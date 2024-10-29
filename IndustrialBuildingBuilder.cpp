#include "IndustrialBuildingBuilder.h"

IndustrialBuildingBuilder& IndustrialBuildingBuilder::setPollutionLevel(float level) {
    this->pollutionLevel = level;
    return *this;
}

IndustrialBuildingBuilder& IndustrialBuildingBuilder::setProductionCapacity(float capacity) {
    this->productionCapacity = capacity;
    return *this;
}
float IndustrialBuildingBuilder::getPollutionLevel() {
	return this->pollutionLevel;
}

float IndustrialBuildingBuilder::getProductionCapacity() {
	return this->productionCapacity;
}

std::unique_ptr<Building> IndustrialBuildingBuilder::build() {
    return std::make_unique<IndustrialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, productionCapacity, pollutionLevel
    );
}