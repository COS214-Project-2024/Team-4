#include "TownHouse.h"
#include <thread>
#include <chrono>
#include <iostream>

void TownHouse::construct() {
	// TODO - implement TownHouse::construct
	throw "Not yet implemented";
}

int TownHouse::getEconomicGrowth() {
	// TODO - implement TownHouse::getEconomicGrowth
	throw "Not yet implemented";
}

int TownHouse::getResourceConsumption() {
	// TODO - implement TownHouse::getResourceConsumption
	throw "Not yet implemented";
}

int TownHouse::getSatisfaction() {
	// TODO - implement TownHouse::getSatisfaction
	throw "Not yet implemented";
}

double TownHouse::collectIncome() {
	double totalIncome = 0;
	for (int i = 0; i < occupants.size(); i++) {
		totalIncome += occupants[i]->getIncome();
	}
	return totalIncome;
}

void TownHouse::undocollectIncome()  {
	// TODO - implement TownHouse::undoCollectTaxes
	throw "Not yet implemented";
}

double TownHouse::collectTaxes() {
	double totalTaxes = 0;
	for (auto& occupant : occupants) {
		if (occupant->canPayTax()) {
			// Calculate and add the tax for the occupant
			double taxAmount = occupant->getIncome() * occupant->getTaxRate();
			totalTaxes += taxAmount;

			// Set tax cooldown for the occupant to prevent immediate re-payment
			occupant->setTaxCooldown(true);
		}
	}

	// // Simulate sending taxes to the government (this could be a call to another class)
	// sendTaxesToGovernment(totalTaxes);

	// Start a cooldown timer for occupants in a separate thread
	std::thread([this]() {
		// Cooldown period in seconds
		const int taxCooldownPeriod = 10;

		// Wait for the cooldown period
		std::this_thread::sleep_for(std::chrono::seconds(taxCooldownPeriod));

		// Reset the cooldown status for each occupant
		for (auto& occupant : occupants) {
			occupant->setTaxCooldown(false);
			std::cout << occupant->getName() << " is now ready to pay tax again.\n";
		}
	}).detach();

	return totalTaxes;
}
