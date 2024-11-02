#ifndef TOWNHOUSE_H
#define TOWNHOUSE_H

#include "Building.h"
#include "Citizen.h"
#include <vector>

class TownHouse : Building {

private:
	vector<Citizen*> occupants;
	char bType;

public:
	void construct();

	int getEconomicGrowth();

	int getResourceConsumption();

	int getSatisfaction();

	double collectIncome();
	void undocollectIncome();
	double collectTaxes();
};

#endif
