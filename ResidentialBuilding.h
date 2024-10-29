#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"
//#include "Citizen.h"
#include<string>
using namespace std;

class ResidentialBuilding :public Building {

private:
	 int residentialUnits = 0;
    float comfortLevel = 0.0f;
	string bType;


public:
	 ResidentialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        int residentialUnits, float comfortLevel);

	string getType() const override;

	void updateImpacts()override;
	void construct() override;
	void upgradeComfort(float comfort);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
