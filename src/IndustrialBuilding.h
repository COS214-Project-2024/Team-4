#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H
#include "Building.h"
#include<string>
#include<iostream>
using namespace std;

class IndustrialBuilding :public Building {

private:
	float pollutionLevel;
	float productionCapacity;
	string bType;

public:
	IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity);

	string getType()const override;

	void construct() override;

	void updateImpacts()override;

	void upgradeTech(float techLevel);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
