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

//pay taxes for the building
double ResidentialBuilding::payTaxes(TaxType* taxType) {
for (Citizen* citizen : residents) {
    citizen->setTaxRate(taxType->getTaxRate());
    propertyTax += citizen->calculateTax();
    householdIncome += citizen->getIncome();
  }
  return propertyTax;
}



//calculate property tax of the building
double ResidentialBuilding::calculatePropertyTax() {
  propertyTax = residentialUnits * 0.1f;
  return propertyTax;
}

//calculate household income of the building

double ResidentialBuilding::calculateHouseholdIncome() {
  householdIncome = residentialUnits * 1000.0f;
  return householdIncome;
}


//add residents to the building
void ResidentialBuilding::addResidents(Citizen* citizen) {
  residents.push_back(citizen);
}

//undo collecting taxes from the building
void ResidentialBuilding::undoCollectTaxes() {
  propertyTax = 0;
  householdIncome = 0;
}

//get residential units of the building
int ResidentialBuilding::getResidentialUnits() const {
  return residentialUnits;
}

