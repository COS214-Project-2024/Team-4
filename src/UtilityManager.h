#ifndef UTILITYMANAGER_H
#define UTILITYMANAGER_H

#include "CityGrowthObserver.h"

class UtilityManager : CityGrowthObserver {


public:
	void update(int newPopulation);
};

#endif
