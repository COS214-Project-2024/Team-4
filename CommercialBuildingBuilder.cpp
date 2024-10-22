#include "CommercialBuildingBuilder.h"

void CommercialBuildingBuilder::setBusinessUnits(int units) {
	this->businessUnits = units;
}

int CommercialBuildingBuilder::getBusinessUnits() {
	return this->businessUnits;
}

float CommercialBuildingBuilder::getCustomerTraffic() {
	return this->customerTraffic;
}

void CommercialBuildingBuilder::setCustomerTraffic(float customerTraffic) {
	this->customerTraffic = customerTraffic;
}

CommercialBuilding CommercialBuildingBuilder::build() {
	// TODO - implement CommercialBuildingBuilder::build
	throw "Not yet implemented";
}
