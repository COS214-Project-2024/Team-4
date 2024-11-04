#include "PopulationManager.h"
#include "Citizen.h"
#include "CitizenState.h"
#include "EmployedState.h"
#include "UnemployedState.h"
#include "SatisfiedState.h"
#include "UnsatisfiedState.h"
#include "LeavingCityState.h"
#include "MaleCitizen.h"
#include "FemaleCitizen.h"
#include "JobSatisfactionStrategy.h"
#include "HousingSatisfactionStrategy.h"
#include "TaxSatisfactionStrategy.h"
#include "BuildingManager.h" // Include this to use BuildingManager in PopulationManager
#include "Jobs.h" 
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

PopulationManager::PopulationManager() 
    : jobSatisfaction(std::make_shared<JobSatisfactionStrategy>()),
      housingSatisfaction(std::make_shared<HousingSatisfactionStrategy>()) 
{
    std::srand(std::time(nullptr)); // Seed randomness for the simulation
}

// Adding a citizen to the population
void PopulationManager::addCitizen(std::shared_ptr<Citizen> citizen) {
    citizens.push_back(citizen);
}

// Simulate population growth randomly
void PopulationManager::simulatePopulationGrowth() {
    if (std::rand() % 2 == 0) {
        addRandomCitizen();
    } else {
        removeRandomCitizen();
    }
    removeLeavingCitizens(); // Remove unhappy citizens if any
}

void PopulationManager::findJobsForUnemployedCitizens(BuildingManager& buildingManager) {
    for (auto& citizen : citizens) {
        // Check if the citizen is unemployed
        if (!citizen->isEmployed()) {
            bool jobFound = false;

            // Try to find a job for the citizen in available buildings
            for (const auto& building : buildingManager.getBuildings()) {
                // Get available jobs in the building
                const auto& jobs = building->getJobs();
                
                // Check if there are jobs available in this building
                if (!jobs.empty()) {
                    // Select a random job title from the available jobs
                    std::shared_ptr<Jobs> randomJob = jobs[std::rand() % jobs.size()];
                    std::string jobTitle = randomJob->getTitle();

                    // Attempt to search and apply for this job
                    citizen->searchAndApplyForJob(buildingManager, building.get(), jobTitle);
                        
                    
                }
            }

            // If no job was found, print a message
            if (!jobFound) {
                std::cout << citizen->getName() << " could not find a job.\n";
            }
        }
    }
}
// Add a random citizen to the population
void PopulationManager::addRandomCitizen() {
    std::shared_ptr<Citizen> citizen;
    if (std::rand() % 2 == 0) {
        citizen = std::make_shared<MaleCitizen>("RandomMale", 0);
    } else {
        citizen = std::make_shared<FemaleCitizen>("RandomFemale", 0);
    }
    citizens.push_back(citizen);
    std::cout << "Citizen added randomly. Total population: " << getPopulation() << std::endl;
    citizen->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
    citizen->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
    citizen->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());

}

// // Remove a random citizen from the population
// void PopulationManager::removeRandomCitizen() {
//     if (!citizens.empty()) {
//         // Generate a random index within bounds
//         int index = std::rand() % citizens.size();

//         // Safely retrieve the citizen before erasing
//         std::shared_ptr<Citizen> citizenToRemove = citizens[index];
        // Safely retrieve the citizen before erasing
        std::shared_ptr<Citizen> citizenToRemove = citizens[index];
        
            if (auto job = citizenToRemove->getjobobj()) {
                job->unOcuppy();
            }

        citizenToRemove->unsetJob();

//         citizenToRemove->removeSatisfactionStrategy();
//         // Detach any observers if necessary (only if needed for your observer design)
//         citizenToRemove->detachAllObservers();

//         // Remove the citizen from the vector
//         citizens.erase(citizens.begin() + index);

//         // Log the removal
//         std::cout << "Citizen " << citizenToRemove->getName() 
//                   << " removed randomly. Total population: " << getPopulation() << std::endl;
//     }
// }



// Remove citizens who are in a LeavingCityState
// void PopulationManager::removeLeavingCitizens() {
//     auto it = std::remove_if(citizens.begin(), citizens.end(),
//                              [](const std::shared_ptr<Citizen>& citizen) {
//                                  return citizen->isLeaving();
//                              });
//     if (it != citizens.end()) {
//         citizens.erase(it, citizens.end());
//         std::cout << "Unhappy citizens left the city. Total population: " << getPopulation() << std::endl;
//     }
// }
void PopulationManager::removeLeavingCitizens() {
    auto it = std::remove_if(citizens.begin(), citizens.end(),
                             [](const std::shared_ptr<Citizen>& citizen) {
                                 return citizen->isLeaving();
                             });

    if (it != citizens.end()) {
        for (auto iter = it; iter != citizens.end(); ++iter) {
            auto citizenToRemove = *iter;

            // Unoccupy the job if the citizen has one
            if (auto job = citizenToRemove->getjobobj()) {
                job->unOcuppy();
            }
            
            citizenToRemove->unsetJob();

            // Remove satisfaction strategy for the citizen
            citizenToRemove->removeSatisfactionStrategy();

            // Detach all observers
            citizenToRemove->detachAllObservers();

            // Log the removal
            std::cout << "Citizen " << citizenToRemove->getName()
                      << " left the city. Total population: " << getPopulation() << std::endl;
        }

        // Erase the citizens marked for removal
        citizens.erase(it, citizens.end());
    }
}

// Get the current population count
int PopulationManager::getPopulation() {
    return citizens.size();
}

// Get the list of all citizens
const std::vector<std::shared_ptr<Citizen>>& PopulationManager::getCitizens() const {
    return citizens;
}

// Update citizens' age each cycle
void PopulationManager::updateCitizensAge() {
    for (auto& citizen : citizens) {
        citizen->incrementAge();
        if (citizen->getAge() == 18) {
            if (std::rand() % 2 == 0) {
                citizen->addSatisfactionStrategy(jobSatisfaction);
                std::cout << citizen->getName() << " turned 18 and received Job Satisfaction Strategy.\n";
            } else {
                citizen->addSatisfactionStrategy(housingSatisfaction);
                std::cout << citizen->getName() << " turned 18 and received Housing Satisfaction Strategy.\n";
            }
        }
    }
}

// Manage relationships between citizens
void PopulationManager::manageRelationships() {
    std::vector<std::shared_ptr<Citizen>> newCitizens;
    for (auto& citizen : citizens) {
        if (citizen->getRelationshipStatus() == "Single" && std::rand() % 10 == 0) {
            citizen->setRelationshipStatus("Dating");
            std::cout << citizen->getName() << " is now dating.\n";
        } else if (citizen->getRelationshipStatus() == "Dating") {
            if (std::rand() % 20 == 0) {
                citizen->setRelationshipStatus("Married");
                std::cout << citizen->getName() << " just got married!\n";
            } else if (std::rand() % 15 == 0) {
                citizen->setRelationshipStatus("Single");
                std::cout << citizen->getName() << " broke up and is now single.\n";
            }
        }
        if (citizen->getRelationshipStatus() == "Married" && citizen->getMarriageDuration() >= 3) {
            std::shared_ptr<Citizen> child;
            if (std::rand() % 2 == 0) {
                child = std::make_shared<MaleCitizen>("RandomMale", 0);
            } else {
                child = std::make_shared<FemaleCitizen>("RandomFemale", 0);
            }
            child->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
            child->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
            child->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());
            newCitizens.push_back(child);
            citizen->resetMarriageDuration();
            std::cout << citizen->getName() << " has a new child.\n";
            citizen->addChild();
        }
        if (citizen->getRelationshipStatus() == "Married") {
            citizen->incrementMarriageDuration();
        }
    }
    citizens.insert(citizens.end(), newCitizens.begin(), newCitizens.end());
}

// Update satisfaction for all eligible citizens
void PopulationManager::updateCitizensSatisfaction() {
    for (auto& citizen : citizens) {
        if (citizen->getAge() >= 18) {
            citizen->updateSatisfaction();
        }
    }
}

// Check and update citizens' states based on satisfaction levels
void PopulationManager::checkCitizenStates() {
    for (auto& citizen : citizens) {
        if (citizen->getAge() >= 18) {
            if (citizen->getSatisfactionLevel() < 20) {
                citizen->setState(new UnsatisfiedState());
            } else if (citizen->getSatisfactionLevel() > 80) {
                citizen->setState(new SatisfiedState());
            } else if (citizen->getSatisfactionLevel() == 0) {
                citizen->setState(new LeavingCityState());
            }
        }
    }
}

void PopulationManager::removeRandomCitizen() {
    if (!citizens.empty()) {
        // Generate a random index within bounds
        int index = std::rand() % citizens.size();

        // Safely retrieve the citizen before erasing
        std::shared_ptr<Citizen> citizenToRemove = citizens[index];

            if (auto job = citizenToRemove->getjobobj()) {
                job->unOcuppy();
            }

        citizenToRemove->removeSatisfactionStrategy();
        // Detach any observers if necessary (only if needed for your observer design)
        citizenToRemove->detachAllObservers();

        // Remove the citizen from the vector
        citizens.erase(citizens.begin() + index);

        // Log the removal
        std::cout << "Citizen " << citizenToRemove->getName() 
                  << " removed randomly. Total population: " << getPopulation() << std::endl;
    }
}
void PopulationManager::removeLeavingCitizens() {
    auto it = std::remove_if(citizens.begin(), citizens.end(),
                             [](const std::shared_ptr<Citizen>& citizen) {
                                 return citizen->isLeaving();
                             });

    if (it != citizens.end()) {
        for (auto iter = it; iter != citizens.end(); ++iter) {
            auto citizenToRemove = *iter;

            // Unoccupy the job if the citizen has one
            if (auto job = citizenToRemove->getjobobj()) {
                job->unOcuppy();
            }

            // Remove satisfaction strategy for the citizen
            citizenToRemove->removeSatisfactionStrategy();

            // Detach all observers
            citizenToRemove->detachAllObservers();

            // Log the removal
            std::cout << "Citizen " << citizenToRemove->getName()
                      << " left the city. Total population: " << getPopulation() << std::endl;
        }

        // Erase the citizens marked for removal
        citizens.erase(it, citizens.end());
    }
}