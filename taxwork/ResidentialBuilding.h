#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"
#include "Citizen.h"
#include<iostream>
#include<string>
using namespace std;

class ResidentialBuilding :public Building {

private:
	 int residentialUnits = 0;
    float comfortLevel = 0.0f;
	string bType;
	double propertyTax;
	double householdIncome;
	vector<Citizen*> residents;
public:
	 ResidentialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        int residentialUnits, float comfortLevel);

	string getType() const override;

	void updateImpacts()override;
	void construct() override;
	void upgradeComfort(float comfort);
	double collectTaxes() override;
	void undoCollectTaxes() override;
	int getResidentialUnits() const;
	void addResidents(Citizen* citizen);
	void removeResidents(Citizen* citizen);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();

	double calculatePropertyTax();

	double calculateHouseholdIncome();


};

#endif
