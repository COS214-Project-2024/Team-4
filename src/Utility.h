#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
//#include "Citizen.h"
#include "ResourceType.h"
#include "UtilityMediator.h"

class Utility {

	protected:
		 UtilityMediator* mediator;  // Reference to the mediator for managing resources
	public:
		// void supplyPower(Building *building);
		// void supplyWater(Building *building);
		// // void manageWaste(Citizen *citizen);
		// void manageSewage(Building *building);
		// Utility();

		Utility(UtilityMediator* mediator) : mediator(mediator) {}

		virtual void registerBuilding(Building* building) = 0;

		virtual void supplyResources(Building* building) = 0;

		//virtual void adjustForCitizen(Citizen* citizen) = 0;

		virtual void adjustForPopulation(int newPopulation) = 0;  // New method

		virtual ~Utility() = default;
};

#endif
