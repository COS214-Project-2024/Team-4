
#ifndef BUILDING_H
#define BUILDING_H
#include<string>
using namespace std;    

class Building {

protected:
	string name;
	float area;
	int floors;
	int capacity;
	float citizenSatisfaction;
	float economicGrowth;
	float resourceConsumption;

public:
    Building(const std::string& name, float area, int floors, int capacity,
             float satisfactionImpact, float growthImpact, float consumption);

    void setName(string name);
    
	virtual void construct() = 0;

	virtual ~Building() = default;

	float getSatisfaction()const;

	float getEconomicGrowth()const;

	float getResourceConsumption()const;
	
	virtual void updateImpacts() = 0;

	virtual string getType()const = 0;
	virtual double collectIncome() = 0;
	virtual void undoCollectIncome() = 0;

protected:
	Building(int Builder);

private:
	virtual void calculateSatisfactionImpact() = 0;

	virtual void calculateEconomicImpact() = 0;

	virtual void calculateResourceConsumption() = 0;
};

#endif
