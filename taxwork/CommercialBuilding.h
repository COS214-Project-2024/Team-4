#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
#include "Building.h"
#include<string>
#include<iostream>
using namespace std;

class CommercialBuilding :public Building {

private:
	int businessUnits;
	float customerTraffic;
	string bType;

public:
	CommercialBuilding(const std::string& name, float area, int floors, int capacity,
							float citizenSatisfaction, float economicGrowth, float resourceConsumption,
							int businessUnits, float customerTraffic);

	string getType()const override;

public:
	void updateImpacts()override;

	void updateCustomer(int traffic);

    void construct() override;

	double collectTaxes()override;

	void undoCollectTaxes()override;


protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif // COMMERCIALBUILDING_H
