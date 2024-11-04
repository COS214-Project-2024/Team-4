#include "WaterSupply.h"
#include <iostream>

WaterSupply::WaterSupply(UtilityMediator* mediator) : Utility(mediator) {}

void WaterSupply::registerBuilding(Building* building) {
    std::cout << "Building registered with WaterSupply.\n";
}

void WaterSupply::supplyResources(Building* building) {
    if (mediator->requestResources(ResourceType::Water, 30)) {
        std::cout << "Water supplied to building.\n";
    } else {
        std::cout << "Insufficient water to supply to building.\n";
    }
}

void WaterSupply::adjustForPopulation(int newPopulation) {
    std::cout << "Adjusting water supply based on new population size: " << newPopulation << "\n";
}

// void WaterSupply::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting water supply based on citizen's requirements.\n";
// }