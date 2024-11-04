#ifndef SEWAGEMANAGEMENT_H
#define SEWAGEMANAGEMENT_H

#include "Utility.h"

class SewageManagement : public Utility {

public:
    SewageManagement(UtilityMediator* mediator);

	void registerBuilding(Building* building) override;
    void supplyResources(Building* building) override;
    // void adjustForCitizen(Citizen* citizen) override;
};

#endif
