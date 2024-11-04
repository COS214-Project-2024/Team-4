/**
 * @file BuildingManager.cpp
 * @brief Implementation of the BuildingManager class.
 * 
 * This file contains the implementation of the BuildingManager class, which manages buildings and citizens.
 * It includes methods to add buildings and citizens, assign jobs to citizens, release citizens from jobs,
 * list all jobs in a building, and find available jobs across all buildings.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city buildings and their properties.
 */

#include "BuildingManager.h"
#include "Building.h"
#include <iostream>
#include <algorithm>

/**
 * @brief Constructs a new BuildingManager object.
 * 
 * @param buildingList A list of buildings to be managed.
 */
BuildingManager::BuildingManager(const std::vector<std::shared_ptr<Building>>& buildingList)
    : buildings(buildingList) {}

/**
 * @brief Adds a building to the list of managed buildings.
 * 
 * @param building Pointer to the building to be added.
 */
void BuildingManager::addBuilding(Building* building) {
    buildings.push_back(std::shared_ptr<Building>(building));
}

/**
 * @brief Adds a citizen to the list of managed citizens.
 * 
 * @param citizen Pointer to the citizen to be added.
 */
void BuildingManager::addCitizen(Citizen* citizen) {
    citizens.push_back(citizen);
}

/**
 * @brief Assigns a job to a citizen if the job is available in the specified building.
 * 
 * @param jobTitle The title of the job to be assigned.
 * @param citizen Pointer to the citizen to be assigned the job.
 * @param building Pointer to the building where the job is located.
 * @return true if the job was successfully assigned to the citizen.
 * @return false if the job could not be assigned.
 */
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

            citizen->employed = true;
            return true;
        }
    }

    std::cout << "Job " << jobTitle << " is not available in " << building->getName() << std::endl;
    return false;
}

/**
 * @brief Releases a citizen from their job by updating both the citizen and the job's state.
 * 
 * @param citizen Pointer to the citizen to be released from their job.
 */
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

/**
 * @brief Lists all jobs in the specified building.
 * 
 * @param building Pointer to the building whose jobs are to be listed.
 */
void BuildingManager::listAllJobsInBuilding(const Building* building) const {
    std::cout << "Jobs in " << building->getName() << ":\n";
    building->listJobs();
}

/**
 * @brief Gets the list of managed buildings.
 * 
 * @return std::vector<std::shared_ptr<Building>> The list of managed buildings.
 */
std::vector<std::shared_ptr<Building>> BuildingManager::getBuildings() {
    return buildings;
}

/**
 * @brief Finds an available job across all buildings.
 * 
 * @return std::shared_ptr<Jobs> A shared pointer to an available job, or nullptr if no jobs are available.
 */
std::shared_ptr<Jobs> BuildingManager::findAvailableJob() {
    for (auto& building : buildings) {
        auto job = building->getAvailableJob();  // Get an available job from each building
        if (job) {
            return job;  // Return the first available job found
        }
    }
    return nullptr;  // No jobs available across buildings
}