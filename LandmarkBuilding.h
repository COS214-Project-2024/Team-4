#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

class LandmarkBuilding : Building {

private:
	int visitorCapacity;
	float culturalValue;
	char bType;

public:
	LandmarkBuilding(int Builder);

	string getType();

public:
	void updateImpacts();

	void hostEvent();

private:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
