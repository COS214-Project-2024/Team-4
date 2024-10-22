#include "ResidentialBuildingBuilder.h"

void ResidentialBuildingBuilder::setResidentialUnit(int unit) {
	this->residentialUnit = unit;
}

void ResidentialBuildingBuilder::setComfort(float comfort) {
	this->comfort = comfort;
}

int ResidentialBuildingBuilder::getResidentialUnit() {
	return this->residentialUnit;
}

float ResidentialBuildingBuilder::getComfort() {
	return this->comfort;
}

ResidentialBuilding ResidentialBuildingBuilder::build() {
	// TODO - implement ResidentialBuildingBuilder::build
	throw "Not yet implemented";
}
