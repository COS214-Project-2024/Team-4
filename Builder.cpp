#include "Builder.h"
//abstract class

Builder& Builder::setName(string name) {
    this->name = name;
    return *this;
}

Builder& Builder::setArea(float area) {
    this->area = area;
    return *this;
}

Builder& Builder::setFloors(int floors) {
    this->floors = floors;
    return *this;
}

Builder& Builder::setCapacity(int capacity) {
    this->capacity = capacity;
    return *this;
}

Builder& Builder::setCitizenSatisfaction(float citizenSatisfaction) {
    this->citizenSatisfaction = citizenSatisfaction;
    return *this;
}

Builder& Builder::setEconomicGrowth(float economicGrowth) {
    this->economicGrowth = economicGrowth;
    return *this;
}

Builder& Builder::setResourceConsumption(float resourceConsumption) {
    this->resourceConsumption = resourceConsumption;
    return *this;
}
// Builder Builder::setName(string name) {
// 	// TODO - implement Builder::setName
// 	throw "Not yet implemented";
// }

// Builder Builder::setArea(float area) {
// 	// TODO - implement Builder::setArea
// 	throw "Not yet implemented";
// }

// Builder Builder::setFloors(int floors) {
// 	// TODO - implement Builder::setFloors
// 	throw "Not yet implemented";
// }

// Builder Builder::setCapacity(int capacity) {
// 	// TODO - implement Builder::setCapacity
// 	throw "Not yet implemented";
// }

// Builder Builder::setCitizenSatisfaction(float citizenSatisfaction) {
// 	// TODO - implement Builder::setCitizenSatisfaction
// 	throw "Not yet implemented";
// }

// Builder Builder::setEconomicGrowth(float economicGrowth) {
// 	// TODO - implement Builder::setEconomicGrowth
// 	throw "Not yet implemented";
// }

// Builder Builder::setResourceConsumption(float resourceConsumption) {
// 	// TODO - implement Builder::setResourceConsumption
// 	throw "Not yet implemented";
// }

