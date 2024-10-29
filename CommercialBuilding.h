#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

class CommercialBuilding : Building {

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

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
