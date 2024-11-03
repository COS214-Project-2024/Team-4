#ifndef WATERSUPPLY_H
#define WATERSUPPLY_H

#include "Utility.h"

class WaterSupply: public Utility {

public:
    WaterSupply(UtilityMediator* mediator);

	void registerBuilding(Building* building) override;
    void supplyResources(Building* building) override;
    void adjustForPopulation(int newPopulation) override;
    //void adjustForCitizen(Citizen* citizen) override;
};

#endif
