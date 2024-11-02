#include "SewageManagement.h"
#include <iostream>

SewageManagement::SewageManagement(UtilityMediator* mediator) : Utility(mediator) {}

void SewageManagement::registerBuilding(Building* building) {
    std::cout << "Building registered with SewageManagement.\n";
}

void SewageManagement::supplyResources(Building* building) {
    if (mediator->requestResources(ResourceType::Sewage, 20)) {
        std::cout << "Sewage management service provided to building.\n";
    } else {
        std::cout << "Insufficient sewage capacity for building.\n";
    }
}

// void SewageManagement::adjustForCitizen(Citizen* citizen) {
//     std::cout << "Adjusting sewage management based on citizen's requirements.\n";
// }
