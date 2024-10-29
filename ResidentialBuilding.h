#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

class ResidentialBuilding : Building {

private:
	int residentialUnit;
	float comfort;
	vector<Citizen*> occupants;
	char bType;

public:
	ResidentialBuilding(int Builder);

	string getType();

public:
	void updateImpacts();

	void upgradeComfort(float comfort);

protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif
