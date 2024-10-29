#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

class IndustrialBuilding : Building {

private:
	float pollutionLevel;
	float productionCapacity;
	char bType;

public:
	IndustrialBuilding(int Builder);

	string getType();

public:
	void updateImpacts();

	void upgradeTech();

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
