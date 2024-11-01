#include "TownHouse.h"

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
