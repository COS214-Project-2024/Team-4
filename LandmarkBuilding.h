#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H
#include "Building.h"
#include<string>
using namespace std;

class LandmarkBuilding :public Building {

private:
	int visitorCapacity;
	float culturalValue;
	string bType;

public:
	LandmarkBuilding(const std::string& name, float area, int floors,
                                         int capacity, float citizenSatisfaction,
                                         float economicGrowth, float resourceConsumption,
                                         int visitorCapacity, float culturalValue);

	string getType()const override;
	void updateImpacts()override;
	void construct() override;
	void hostEvent(int visitors);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
