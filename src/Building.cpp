#include "Building.h"
#include <iostream>

// Primary constructor
Building::Building(const std::string& name, float area, int floors, int capacity,
                   float satisfactionImpact, float growthImpact, float consumption)
    : name(name), area(area), floors(floors), capacity(capacity),
      citizenSatisfaction(satisfactionImpact), economicGrowth(growthImpact),
      resourceConsumption(consumption) {}

// Secondary constructor (e.g., for use with Builder pattern)
Building::Building(int Builder) {
    // This constructor might initialize certain defaults or setup values specific to the "Builder" type.
    // Example defaults if using Builder (adjust as needed):
    this->name = "Default Building";
    this->area = 500.0f;
    this->floors = 2;
    this->capacity = 100;
    this->citizenSatisfaction = 10.0f;
    this->economicGrowth = 5.0f;
    this->resourceConsumption = 2.0f;
}

// Getters
float Building::getSatisfaction() const { return citizenSatisfaction; }
float Building::getEconomicGrowth() const { return economicGrowth; }
float Building::getResourceConsumption() const { return resourceConsumption; }

// Adds a job to the building
void Building::addJob(std::shared_ptr<Jobs> job) {
    jobs.push_back(job);
}

// Lists all jobs in the building
void Building::listJobs() const {
    for (const auto& job : jobs) {
        job->displayJobInfo();  // Display job information for each job
    }
}

// Hires an employee for a job if available
bool Building::hireEmployee(const std::string& jobTitle) {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle && !job->isOccupied()) {
            job->hireEmployee();
            return true;
        }
    }
    return false;  // Job not found or no positions available
}

// Releases an employee from a job
void Building::releaseEmployee(const std::string& jobTitle) {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle) {
            job->releaseEmployee();
            break;
        }
        
    }
}

// Provides access to an available job
std::shared_ptr<Jobs> Building::getAvailableJob() {
    for (auto& job : jobs) {
        if (!job->isOccupied()) {
            return job;  // Return the first unoccupied job
        }
    }
    return nullptr;  // No available jobs
}


// Displays specific job information by title
void Building::displayJobInfo(const std::string& jobTitle) const {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle) {
            job->displayJobInfo();
            break;
        }
    }
}

 const std::vector<std::shared_ptr<Jobs>>& Building::getJobs() const{
    return jobs;
}

// Setters
void Building::setName(const std::string& name) { this->name = name; }
std::string Building::getName() const { return name; }
//collect taxes from the building

double Building::payTaxes(TaxType* taxType) {
	// Placeholder for tax collection logic
    taxType->calculateTax(0.0);
    return 0.0;
}

//undo collecting taxes from the building
void Building::undoCollectTaxes() {
	// Placeholder for undoing tax collection logic
}

void Building::addCitizen(Citizen* citizen) {
    // Placeholder for adding citizens to a building
}

void Building::addBusiness(std::shared_ptr<Business> business){
    // Placeholder for adding businesses to a building
}
