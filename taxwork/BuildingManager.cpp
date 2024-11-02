#include "BuildingManager.h"
#include <iostream>
#include <algorithm>

namespace YourNamespace {

// Adds a building to the list of managed buildings
void BuildingManager::addBuilding(Building* building) {
    buildings.push_back(building);
}

//collects all taxes from the citizens in all buildings
double BuildingManager::collectAllTaxes() {
    double totalTax = 0.0;
    for (Building* building : buildings) {
        if(building->getType() == "Residential"){
            totalTax+=building->collectTaxes();
        }else if (building->getType() == "Commercial")
        {
            totalTax+=building->collectTaxes();
        } else if (building->getType() == "Industrial")
        {
            totalTax+=building->collectTaxes();
        
        } else if (building->getType() == "Government")
        {
            std::cout<<"Government building does not collect taxes"<<std::endl;
        } else
        {
            std::cout<<"Building type cannot be taxed"<<std::endl;
        }
    }
    return totalTax;
}

// Adds a citizen to the list of managed citizens
void BuildingManager::addCitizen(Citizen* citizen) {
    citizens.push_back(citizen);
}

// Assigns a job to a citizen if the job is available in the specified building
bool BuildingManager::assignJobToCitizen(const std::string& jobTitle, Citizen* citizen, Building* building) {
    // Search for the job in the building
    for (Jobs& job : building->getJobs()) {
        if (job.getTitle() == jobTitle && job.getAvailablePositions() > 0) {
            // Hire the citizen for the job if a position is available
            if (job.hireEmployee()) {
                citizen->setJobTitle(jobTitle);
                std::cout << citizen->getName() << " assigned to " << jobTitle << " in " << building->getName() << std::endl;
                return true;
            }
        }
    }
    std::cout << "Job " << jobTitle << " is not available in " << building->getName() << std::endl;
    return false;
}

// Releases a citizen from their job by updating both the citizen and the job's state
void BuildingManager::releaseCitizenFromJob(Citizen* citizen) {
    for (Building* building : buildings) {
        for (Jobs& job : building->getJobs()) {
            if (job.getTitle() == citizen->getJob()) {
                job.releaseEmployee();
                citizen->setJobTitle("Unemployed");
                std::cout << citizen->getName() << " released from " << job.getTitle() << " in " << building->getName() << std::endl;
                return;
            }
        }
    }
    std::cout << citizen->getName() << " does not have an assigned job." << std::endl;
}

// Lists all jobs in the specified building
void BuildingManager::listAllJobsInBuilding(const Building* building) const {
    std::cout << "Jobs in " << building->getName() << ":\n";
    building->listJobs();
}

} // namespace YourNamespace
