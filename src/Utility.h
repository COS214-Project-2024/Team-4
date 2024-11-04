#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
//#include "Citizen.h"
#include "ResourceType.h"
#include "UtilityMediator.h"
#include <memory>
#include <map>

class Utility {

	protected:
		 UtilityMediator* mediator;  // Reference to the mediator for managing resources
		 std::map<std::string, double> charges; // Track charges for each owner
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

		void chargeOwner(Building* building, double amount) {
			std::string owner = building->getOwner();
			charges[owner] += amount;
		}

		double getCharges(const std::string& owner) const {
			auto it = charges.find(owner);
			return it != charges.end() ? it->second : 0.0;
		}

		virtual ~Utility() = default;
};

#endif
