#include "LandmarkBuilding.h"

//constructor
LandmarkBuilding::LandmarkBuilding(const std::string& name, float area, int floors, int capacity,
                                   float citizenSatisfactionImpact, float economicGrowthImpact,
                                   float resourceConsumption, int visitorCapacity, float culturalValue, bool isHistoric)
 :Building(name, area, floors, capacity, citizenSatisfaction, economicGrowth, resourceConsumption)
										 {
	this->visitorCapacity = visitorCapacity;
	this->culturalValue = culturalValue;
	this->isHistoric = isHistoric;
	this->bType = "Landmark";
}

//get type of building
string LandmarkBuilding::getType()const {
	return this->bType;
}

//update impacts by calculating economic impact, resource consumption and satisfaction impact
void LandmarkBuilding::updateImpacts() {
calculateEconomicImpact();
    calculateResourceConsumption();
    calculateSatisfactionImpact();
}


//host an event in the building
void LandmarkBuilding::hostEvent(int visitors) {
	//not sure yet
	visitorCapacity += visitors;
	 culturalValue += 5.0f;
}

//calculate economic impact of the building
void LandmarkBuilding::calculateEconomicImpact() {
	economicGrowth += visitorCapacity * culturalValue;
}

//calculate resource consumption of the building
void LandmarkBuilding::calculateResourceConsumption() {
	resourceConsumption += visitorCapacity * 0.1;
}

//calculate satisfaction impact of the building
void LandmarkBuilding::calculateSatisfactionImpact() {
	citizenSatisfaction += visitorCapacity * 0.01;
}

//construct the building
void LandmarkBuilding::construct() {
	std::cout<<"============================================================\n";
	std::cout << "Constructing Landmark Building: " << name << std::endl;
    std::cout << "Area: " << area << "\nFloors: " << floors << "\nCapacity: " << capacity << std::endl;
    std::cout << "Visitor Capacity: " << visitorCapacity << "\nCultural Value: " << culturalValue;
	if(isHistoric == true)
	{
		std::cout<<"\nHistoric: Yes\n";
	}
	else
	{
		std::cout<<"\nHistoric: No\n";
	}
         
   	std::cout<<"============================================================\n";

}