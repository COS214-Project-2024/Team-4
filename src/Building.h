#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Jobs.h"
#include "Citizen.h"
#include "Business.h"
class Building {
protected:
    std::string name;
    float area;
    int floors;
    int capacity;
    float citizenSatisfaction;
    float economicGrowth;
    float resourceConsumption;
    std::vector<std::shared_ptr<Jobs>> jobs;  // Collection of jobs as shared pointers

public:
    // Main constructor for setting attributes directly
    Building(const std::string& name, float area, int floors, int capacity,
             float satisfactionImpact, float growthImpact, float consumption);

    // Alternative constructor using an integer parameter, potentially for Builder pattern integration
    Building(int Builder);

    // Setters and getters
    void setName(const std::string& name);
    std::string getName() const;

    virtual void construct() = 0;
    virtual ~Building() = default;

    float getSatisfaction() const;
    float getEconomicGrowth() const;
    float getResourceConsumption() const;

    virtual void updateImpacts() = 0;
    virtual std::string getType() const = 0;

    // Job management methods
    void addJob(std::shared_ptr<Jobs> job);  // Adds a job to the building
    void listJobs() const;  // Lists all jobs in the building
    bool hireEmployee(const std::string& jobTitle);  // Hires an employee for a job if available
    void releaseEmployee(const std::string& jobTitle);  // Releases an employee from a job
    std::shared_ptr<Jobs> getAvailableJob();  // Provides access to an available job

    void displayJobInfo(const std::string& jobTitle) const;  // Displays job information
	const std::vector<std::shared_ptr<Jobs>>& getJobs() const;  // Returns the job list as a const reference
    
	// Collect taxes from the building
	virtual double payTaxes(TaxType* taxType) = 0;

	// Undo collecting taxes from the building
	virtual void undoCollectTaxes() = 0;
    virtual void addCitizen(Citizen* citizen) = 0;
    virtual  void addBusiness(std::shared_ptr<Business> business)= 0;

private:
    virtual void calculateSatisfactionImpact() = 0;
    virtual void calculateEconomicImpact() = 0;
    virtual void calculateResourceConsumption() = 0;
};

#endif // BUILDING_H

