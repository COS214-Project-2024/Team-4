#include "WasteManagement.h"
#include <iostream>

WasteManagement::WasteManagement(UtilityMediator* mediator) : Utility(mediator) {}

void WasteManagement::registerBuilding(Building* building) {
    std::cout << "Building registered with WasteManagement.\n";
}

void WasteManagement::supplyResources(Building* building) {
    std::cout << "Waste management service provided to building.\n";
}

void WasteManagement::adjustForPopulation(int newPopulation) {
    std::cout << "Adjusting waste management based on new population size: " << newPopulation << "\n";
}

// void WasteManagement::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting waste management based on citizen's requirements.\n";
// }
