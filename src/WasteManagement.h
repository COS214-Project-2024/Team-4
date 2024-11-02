#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"

class WasteManagement : public Utility {

public:
    WasteManagement(UtilityMediator* mediator);

	//void manageWaste(Citizen *citizen);
	void registerBuilding(Building* building) override;
    void supplyResources(Building* building) override;
    // void adjustForCitizen(Citizen* citizen) override;
};

#endif
