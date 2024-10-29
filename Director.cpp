#include "Director.h"

void Director::setBuilder(Builder& builder) {
	this->builder = &builder;
}

std::unique_ptr<Building> Director::constructSmallBuilding() {
	builder->setArea(500.0f)
           .setFloors(1)
           .setCapacity(50)
           .setCitizenSatisfaction(1.0f)
           .setEconomicGrowth(0.5f)
           .setResourceConsumption(0.3f);
    return builder->build();
}

std::unique_ptr<Building> Director::constructMediumBuilding() {
	  builder->setArea(1500.0f)
           .setFloors(3)
           .setCapacity(150)
           .setCitizenSatisfaction(2.0f)
           .setEconomicGrowth(1.5f)
           .setResourceConsumption(1.0f);
    return builder->build();
}

std::unique_ptr<Building> Director::constructLargeBuilding() {
	builder->setArea(3000.0f)
           .setFloors(5)
           .setCapacity(300)
           .setCitizenSatisfaction(3.0f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);
    return builder->build();
}
