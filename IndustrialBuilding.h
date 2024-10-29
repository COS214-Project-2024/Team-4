#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "Building.h"
#include<string>
using namespace std;

class IndustrialBuilding :public Building {

private:
	float pollutionLevel;
	float productionCapacity;
	char bType;

public:
	IndustrialBuilding(int Builder);

	string getType();

	void construct() override;

public:
	void updateImpacts();

	void upgradeTech();

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
