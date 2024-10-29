#include "ResidentialBuildingBuilder.h"

ResidentialBuildingBuilder& ResidentialBuildingBuilder::setResidentialUnit(int unit) {
    this->residentialUnit = unit;
    return *this;
}

ResidentialBuildingBuilder& ResidentialBuildingBuilder::setComfort(float comfort) {
    this->comfort = comfort;
    return *this;
}

int ResidentialBuildingBuilder::getResidentialUnit() {
	return this->residentialUnit;
}

float ResidentialBuildingBuilder::getComfort() {
	return this->comfort;
}

std::unique_ptr<Building> ResidentialBuildingBuilder::build() {
    return std::make_unique<ResidentialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, residentialUnit, comfort
    );
}

ResidentialBuildingBuilder::ResidentialBuildingBuilder() {
    // will add 
}