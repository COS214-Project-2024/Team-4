#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H
#include "Building.h"
#include<string>
using namespace std;

class LandmarkBuilding :public Building {

private:
	int visitorCapacity;
	float culturalValue;
	char bType;

public:
	LandmarkBuilding(int Builder);

	string getType();

public:
	void updateImpacts();
	void construct() override;
	void hostEvent();

private:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
