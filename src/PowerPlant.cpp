#include "PowerPlant.h"
#include <iostream>

PowerPlant::PowerPlant(UtilityMediator* mediator) : Utility(mediator) {}

void PowerPlant::registerBuilding(Building* building) {
    // Register the building to receive power
    std::cout << "Building registered with PowerPlant.\n";
}

// void PowerPlant::supplyResources(Building* building) {
//     // Request power from the mediator and supply to the building
//     if (mediator->requestResources(ResourceType::Power, 50)) {
//         std::cout << "Power supplied to building.\n";
//     } else {
//         std::cout << "Insufficient power to supply to building.\n";
//     }
// }
void PowerPlant::supplyResources(Building* building) {
    // Request power from the mediator and supply to the building
    if (mediator->requestResources(ResourceType::Power, 50)) {
        std::cout << "Power supplied to building.\n";
        chargeOwner(building, 50 * 50); // Charge $50 per unit of power supplied
    } else {
        std::cout << "Insufficient power to supply to building.\n";
    }
}

// void PowerPlant::adjustForCitizen(Citizen* citizen) {
//     // Adjust power based on new citizen needs, if required
//     std::cout << "Adjusting power supply based on citizen's requirements.\n";
// }


// void PowerPlant::generateElectricity(Building* building) {
// 	// TODO - implement PowerPlant ::generateElectricity
// 	throw "Not yet implemented";
// }

// void PowerPlant::supplyPower(Building *building) {
// 	// TODO - implement PowerPlant ::supplyPower
// 	throw "Not yet implemented";
// }

// PowerPlant::PowerPlant() {
// 	// TODO - implement PowerPlant ::PowerPlant
// 	//throw "Not yet implemented";
// }

// //? why did it double generate the PowerPlant class from the uml diagram?
// // void PowerPlant::generateElectricity(Building building) {
// // 	// TODO - implement PowerPlant ::generateElectricity
// // 	throw "Not yet implemented";
// // }

// // void PowerPlant::supplyPower(Building building) {
// 	// TODO - implement PowerPlant ::supplyPower
// 	throw "Not yet implemented";
// }

// void PowerPlant::PowerPlant() {
// 	// TODO - implement PowerPlant ::PowerPlant
// 	throw "Not yet implemented";
// }
