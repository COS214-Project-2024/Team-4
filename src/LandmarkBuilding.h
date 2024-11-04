#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H
#include "Building.h"
#include<string>
#include<iostream>
using namespace std;

class LandmarkBuilding :public Building {

private:
	int visitorCapacity;
	float culturalValue;
	bool isHistoric;
	string bType;

public:
	 LandmarkBuilding(const std::string& name, float area, int floors, int capacity,
                     float citizenSatisfactionImpact, float economicGrowthImpact,
                     float resourceConsumption, int visitorCapacity, float culturalValue, bool isHistoric);

	string getType()const override;
	void updateImpacts()override;
	void construct() override;
	void hostEvent(int visitors);

	double payTaxes(TaxType* taxType) override;
	void undoCollectTaxes() override;
	

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
