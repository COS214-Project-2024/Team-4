#ifndef BUILDING_H
#define BUILDING_H
#include<string>
#include<vector>
#include<algorithm>
#include "Jobs.h"
#include "TaxType.h"
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
	 std::vector<Jobs> jobs; 
	std::string owner; // Add owner attribute

public:
    Building(const std::string& name, float area, int floors, int capacity,
             float satisfactionImpact, float growthImpact, float consumption);

    void setName(string name);

	std::string getName()const;
    
	virtual void construct() = 0;

	virtual ~Building() = default;

	float getSatisfaction()const;

	float getEconomicGrowth()const;

	float getResourceConsumption()const;

	virtual void updateImpacts() = 0;

	virtual string getType()const = 0;

	 void addJob(const Jobs& job);                 // Adds a job to the building
    void listJobs() const;                       // Lists all jobs in the building
    bool hireEmployee(const std::string& jobTitle);  // Hires an employee for a job if available
    void releaseEmployee(const std::string& jobTitle); // Releases an employee from a job
	void displayJobInfo(const std::string& jobTitle) const; // Displays job information
    // Accessor for job list, for use by BuildingManager
    std::vector<Jobs>& getJobs();

	// Collect taxes from the building
	virtual double payTaxes(TaxType* taxType) = 0;

	// Undo collecting taxes from the building
	virtual void undoCollectTaxes() = 0;

	//set tax rate for occupants in the building
	//virtual void setTaxRate(double rate) = 0;

	void setOwner(const std::string& owner) { this->owner = owner; }
    std::string getOwner() const { return owner; }

protected:
	Building(int Builder);

private:
	virtual void calculateSatisfactionImpact() = 0;

	virtual void calculateEconomicImpact() = 0;

	virtual void calculateResourceConsumption() = 0;
};

#endif