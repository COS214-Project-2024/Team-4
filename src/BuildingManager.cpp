#include "BuildingManager.h"
#include "Building.h"
#include <iostream>
#include <algorithm>

BuildingManager::BuildingManager(const std::vector<std::shared_ptr<Building>>& buildingList)
    : buildings(buildingList) {}

// Adds a building to the list of managed buildings
void BuildingManager::addBuilding(Building* building) {
    buildings.push_back(std::shared_ptr<Building>(building));
}

// Adds a citizen to the list of managed citizens
void BuildingManager::addCitizen(Citizen* citizen) {
    citizens.push_back(citizen);
}

// Assigns a job to a citizen if the job is available in the specified building
bool BuildingManager::assignJobToCitizen(const std::string& jobTitle, Citizen* citizen, Building* building) {
    if (!building) {
        std::cerr << "Error: Building pointer is null." << std::endl;
        return false;
    }

    auto& jobs = building->getJobs();
    if (jobs.empty()) {
        std::cerr << "Error: No jobs available in building " << building->getName() << std::endl;
        return false;
    }

    for (auto& job : jobs) {
        if (job->getTitle() == jobTitle && !job->isOccupied()) {
            job->hireEmployee();
            citizen->setJobTitle(jobTitle);
            citizen->setIncome(job->getIncome());
            citizen->setJob(job);
            std::cout << citizen->getName() << " assigned to " << jobTitle << " in " 
                      << building->getName() << std::endl;

            citizen->employed = true ;
            return true;
        }
    }

    std::cout << "Job " << jobTitle << " is not available in " << building->getName() << std::endl;
    return false;
}

// Releases a citizen from their job by updating both the citizen and the job's state
void BuildingManager::releaseCitizenFromJob(Citizen* citizen) {
    for (auto& building : buildings) {
        for (auto& job : building->getJobs()) {
            if (job->getTitle() == citizen->getJob()) {
                job->releaseEmployee();
                citizen->setJobTitle("Unemployed");
                std::cout << citizen->getName() << " released from " << job->getTitle() << " in " << building->getName() << std::endl;
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

std::vector<std::shared_ptr<Building>> BuildingManager::getBuildings(){
    return buildings;
}

// Finds an available job across all buildings
std::shared_ptr<Jobs> BuildingManager::findAvailableJob() {
    for (auto& building : buildings) {
        auto job = building->getAvailableJob();  // Get an available job from each building
        if (job) {
            return job;  // Return the first available job found
        }
    }
    return nullptr;  // No jobs available across buildings
}

