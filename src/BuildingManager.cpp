// BuildingManager.cpp

#include "BuildingManager.h"
#include <iostream>

namespace YourNamespace {

void BuildingManager::addBuilding(Building* building) {
    buildings.push_back(building);
}

void BuildingManager::addCitizen(Citizen* citizen) {
    citizens.push_back(citizen);
}

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

void BuildingManager::listAllJobsInBuilding(const Building* building) const {
    std::cout << "Jobs in " << building->getName() << ":\n";
    building->listJobs();
}

// double BuildingManager::collectAllTaxes() {
//     double totalTax = 0.0;
//     for (Building* building : buildings) {
//         std::string type = building->getType();
//         if (type == "Government") {
//             std::cout << "Government building does not collect taxes" << std::endl;
//         } else if (type == "Residential" || type == "Commercial" || type == "Industrial") {
//             totalTax += building->payTaxes();
//         } else {
//             std::cout << "Building type cannot be taxed" << std::endl;
//         }
//     }
//     return totalTax;
// }

} // namespace YourNamespace
