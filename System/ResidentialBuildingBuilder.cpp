#include "ResidentialBuildingBuilder.h"

//sets number of residential units in the building
ResidentialBuildingBuilder& ResidentialBuildingBuilder::setResidentialUnit(int unit) {
    this->residentialUnit = unit;
    return *this;
}

//sets comfort level of the building
ResidentialBuildingBuilder& ResidentialBuildingBuilder::setComfort(float comfort) {
    this->comfort = comfort;
    return *this;
}

//gets number of residential units in the building
int ResidentialBuildingBuilder::getResidentialUnit() {
	return this->residentialUnit;
}

//	gets comfort level of the building
float ResidentialBuildingBuilder::getComfort() {
	return this->comfort;
}

//builds the residential building,sets all the attributes of the building
std::unique_ptr<Building> ResidentialBuildingBuilder::build() {
    return std::make_unique<ResidentialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, residentialUnit, comfort
    );
}

	ResidentialBuildingBuilder::ResidentialBuildingBuilder() {
		// will add 
	}