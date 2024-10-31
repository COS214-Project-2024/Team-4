#ifndef WATERSUPPLY _H
#define WATERSUPPLY _H

#include "Utility.h"

class WaterSupply: Utility {

public:
	Utility mediator;

	void distributeWater(Building *building);

	void supplyWater(Building *building);

	WaterSupply();
};

#endif
