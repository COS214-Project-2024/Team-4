#ifndef UTILITY_H
#define UTILITY_H

#include "Building.h"
//#include "Citizen.h"

class Utility {


public:
	void supplyPower(Building *building);

	void supplyWater(Building *building);

	// void manageWaste(Citizen *citizen);

	void manageSewage(Building *building);

	Utility();
};

#endif
