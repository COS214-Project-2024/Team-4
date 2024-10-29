#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"
//#include "Citizen.h"
#include<string>
using namespace std;

class ResidentialBuilding :public Building {

private:
	int residentialUnit;
	float comfort;
	//vector<Citizen*> occupants;
	char bType;

public:
	ResidentialBuilding(int Builder);

	string getType();

public:
	void updateImpacts();
	void construct() override;
	void upgradeComfort(float comfort);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
