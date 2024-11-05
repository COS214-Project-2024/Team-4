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
	std::shared_ptr<Business> business;

public:
	IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity);

	string getType()const override;

	void construct() override;

	void updateImpacts()override;

	void upgradeTech(float techLevel);

	double payTaxes(TaxType* taxType);
    void undoCollectTaxes();

	void addCitizen(Citizen* citizen);
	void addBusiness(std::shared_ptr<Business> business);
protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
