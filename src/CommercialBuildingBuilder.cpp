#include "CommercialBuildingBuilder.h"

//sets number of business units in the building
CommercialBuildingBuilder& CommercialBuildingBuilder::setBusinessUnits(int units) {
    this->businessUnits = units;
    return *this;
}

//gets number of business units in the building
int CommercialBuildingBuilder::getBusinessUnits() {
	return this->businessUnits;
}

//gets customer traffic in the building
float CommercialBuildingBuilder::getCustomerTraffic() {
	return this->customerTraffic;
}

//sets customer traffic in the building
CommercialBuildingBuilder& CommercialBuildingBuilder::setCustomerTraffic(float traffic) {
    this->customerTraffic = traffic;
    return *this;
}

//builds the commercial building,sets all the attributes of the building
std::unique_ptr<Building> CommercialBuildingBuilder::build() {
    return std::make_unique<CommercialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, businessUnits, customerTraffic
    );
}

CommercialBuildingBuilder::CommercialBuildingBuilder() {
	// will add something
}