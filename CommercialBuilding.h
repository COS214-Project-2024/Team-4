#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H
#include "Building.h"
#include<string>
using namespace std;

class CommercialBuilding :public Building {

private:
	int businessUnits;
	float customerTraffic;
	char bType;

public:
	CommercialBuilding(int Builder);

	string getType();

public:
	void updateImpacts();

	void updateCustomer(int traffic);

    void construct() override;

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
