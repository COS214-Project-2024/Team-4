#include "ResidentialBuilding.h"

//constructor
ResidentialBuilding::ResidentialBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int residentialUnits, float comfortLevel)
    : Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption),
      residentialUnits(residentialUnits), comfortLevel(comfortLevel), bType("Residential") {}


//get type of building
string ResidentialBuilding::getType() const{
	return bType;
}

//update impacts by calculating economic impact, resource consumption and satisfaction impact
void ResidentialBuilding::updateImpacts() {
	calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}

//upgrade comfort level of the building
void ResidentialBuilding::upgradeComfort(float comfort) {
	comfortLevel += comfort;
}

//calculate economic impact of the building
void ResidentialBuilding::calculateEconomicImpact() {
	 economicGrowth = residentialUnits * comfortLevel * 0.5f;
}

//calculate resource consumption of the building
void ResidentialBuilding::calculateResourceConsumption() {
	resourceConsumption = residentialUnits * 0.05f;
}

//calculate satisfaction impact of the building
void ResidentialBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction = comfortLevel * 0.2f;
}

void ResidentialBuilding::construct() {
  std::cout<<"============================================================\n";
	  std::cout << "Constructing Residential Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Residential Units: " << residentialUnits << "\nComfort Level: " << comfortLevel << std::endl;
std::cout<<"============================================================\n";
}


//! below is Neo's code waiting for @abdulrasaqzainab to approve and the citizen class
// // Adds a resident to the building
// void ResidentialBuilding::addResident(Citizen* citizen) {
//     residents.push_back(citizen);
// }

// // Optional: Removes a resident from the building if needed
// void ResidentialBuilding::removeResident(Citizen* citizen) {
//     residents.erase(std::remove(residents.begin(), residents.end(), citizen), residents.end());
// }

// Calculate total resource demand based on all residents
// float ResidentialBuilding::calculateTotalResourceDemand() const {
//     float totalDemand = 0.0f;
//     for (const Citizen* citizen : residents) {
//         totalDemand += citizen->getResourceUsage();  // Assuming getResourceUsage() returns the citizen's resource needs
//     }
//     return totalDemand;
// }
