#ifndef WATERSUPPLY _H
#define WATERSUPPLY _H

#include "Utility.h"

class WaterSupply: public Utility {

public:
    WaterSupply(UtilityMediator* mediator);

	void registerBuilding(Building* building) override;
    void supplyResources(Building* building) override;
    void adjustForCitizen(Citizen* citizen) override;
};

#endif
