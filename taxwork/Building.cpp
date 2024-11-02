#include "Building.h"
//base class for all buildings

//construtor
Building::Building(const std::string& name, float area, int floors, int capacity,
                   float satisfactionImpact, float growthImpact, float consumption)
    {
	this->name = name;
	this->area = area;
	this->floors = floors;
	this->capacity = capacity;
	this->citizenSatisfaction = satisfactionImpact;
	this->economicGrowth = growthImpact;
	this->resourceConsumption = consumption;

	}


//getters
float Building::getSatisfaction() const{
	return this->citizenSatisfaction;
}

float Building::getEconomicGrowth() const{
	return this->economicGrowth;
}

float Building::getResourceConsumption()const {
	return this->resourceConsumption;	
}

//====jobs======
// Adds a job to the building
void Building::addJob(const Jobs& job) {
    jobs.push_back(job);
}

// Lists all jobs in the building
// void Building::listJobs() const {
//     std::cout << "Jobs in " << name << ":\n";
//     for (const auto& job : jobs) {
//         job.displayJobInfo();
//     }
// }

// Hires an employee for a job if available
bool Building::hireEmployee(const std::string& jobTitle) {
    auto it = std::find_if(jobs.begin(), jobs.end(),
                           [&](const Jobs& job) { return job.getTitle() == jobTitle; });
    if (it != jobs.end() && it->getAvailablePositions() > 0) {
        it->hireEmployee();
        return true;
    }
    return false;  // Job not found or no positions available
}

// Releases an employee from a job
void Building::releaseEmployee(const std::string& jobTitle) {
    auto it = std::find_if(jobs.begin(), jobs.end(),
                           [&](const Jobs& job) { return job.getTitle() == jobTitle; });
    if (it != jobs.end()) {
        it->releaseEmployee();
    }
}

// Provides access to the jobs for BuildingManager
std::vector<Jobs>& Building::getJobs() {
    return jobs;
}

// Displays job information
void Building::displayJobInfo(const std::string& jobTitle) const {
	auto it = std::find_if(jobs.begin(), jobs.end(),
						   [&](const Jobs& job) { return job.getTitle() == jobTitle; });
	if (it != jobs.end()) {
		it->displayJobInfo();
	}
}

std::string Building::getName()const{
    return this->name;
}

void Building::listJobs() const {
    for (const auto& job : jobs) {
        job.displayJobInfo();  // Only display job information here
    }
}

//collect taxes from the building
double Building::collectTaxes() {
	// Placeholder for tax collection logic
}

//undo collecting taxes from the building
void Building::undoCollectTaxes() {
	// Placeholder for undoing tax collection logic
}

void Building::undoCollectIncome() {
	// Placeholder for undoing income collection logic
}


