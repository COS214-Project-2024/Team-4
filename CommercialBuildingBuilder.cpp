#include "CommercialBuildingBuilder.h"

CommercialBuildingBuilder& CommercialBuildingBuilder::setBusinessUnits(int units) {
    this->businessUnits = units;
    return *this;
}

int CommercialBuildingBuilder::getBusinessUnits() {
	return this->businessUnits;
}

float CommercialBuildingBuilder::getCustomerTraffic() {
	return this->customerTraffic;
}

CommercialBuildingBuilder& CommercialBuildingBuilder::setCustomerTraffic(float traffic) {
    this->customerTraffic = traffic;
    return *this;
}

std::unique_ptr<Building> CommercialBuildingBuilder::build() {
    return std::make_unique<CommercialBuilding>(
        name, area, floors, capacity, citizenSatisfaction, economicGrowth,
        resourceConsumption, businessUnits, customerTraffic
    );
}

