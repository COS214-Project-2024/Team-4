#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H
#include "Building.h"
//#include "Citizen.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class ResidentialBuilding :public Building {

private:
	int residentialUnits = 0;
    float comfortLevel = 0.0f;
	string bType;

	//vector<Citizen*> occupants;


public:
	 ResidentialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        int residentialUnits, float comfortLevel);

	string getType() const override;

	void updateImpacts()override;
	void construct() override;
	void upgradeComfort(float comfort);

	 // New methods for managing residents
    //void addResident(Citizen* citizen);  
	//void removeResident(Citizen* citizen);  // Optional: For flexibility in managing residents
    float calculateTotalResourceDemand() const;  // Calculate total demand based on residents
 double payTaxes(TaxType* taxType) override;


protected:
	void calculateEconomicImpact();
double totalTaxCollected;
	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
