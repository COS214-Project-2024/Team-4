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
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <ctime>

PopulationManager::PopulationManager() 
    : jobSatisfaction(std::make_shared<JobSatisfactionStrategy>()),
      housingSatisfaction(std::make_shared<HousingSatisfactionStrategy>()) 
{
    // Seed randomness for the simulation
    std::srand(std::time(nullptr));
}

void PopulationManager::update(Citizen* citizen) {
    checkCitizenStates();
}

void PopulationManager::simulatePopulationGrowth() {
    if (std::rand() % 2 == 0) {
        addRandomCitizen();
    } else {
        removeRandomCitizen();
    }
    checkCitizenStates();
    removeLeavingCitizens();
}

void PopulationManager::addCitizen(std::shared_ptr<Citizen> citizen) {
    citizens.push_back(citizen);
    citizen->addObserver(this);  // Register this PopulationManager as an observer
}

void PopulationManager::addRandomCitizen() {
    std::shared_ptr<Citizen> citizen;
            if (std::rand() % 2 == 0) {
                citizen = std::make_shared<MaleCitizen>("RandomMale", 0, "Single", "Unemployed");
            } else {
                citizen = std::make_shared<FemaleCitizen>("RandomFemale", 0, "Single", "Unemployed");
            }

    citizens.push_back(citizen);
    std::cout << "Citizen added randomly. Total population: " << getPopulation() << std::endl;
}

void PopulationManager::removeRandomCitizen() {
    if (!citizens.empty()) {
        int index = std::rand() % citizens.size();
        citizens.erase(citizens.begin() + index);
        std::cout << "Citizen removed randomly. Total population: " << getPopulation() << std::endl;
    }
}

void PopulationManager::removeLeavingCitizens() {
    auto it = std::remove_if(citizens.begin(), citizens.end(),
                             [](const std::shared_ptr<Citizen>& citizen) {
                                 return citizen->isLeaving();
                             });
    if (it != citizens.end()) {
        citizens.erase(it, citizens.end());
        std::cout << "Unhappy citizens left the city. Total population: " << getPopulation() << std::endl;
    }
}

int PopulationManager::getPopulation() {
    return citizens.size();
}

const std::vector<std::shared_ptr<Citizen>>& PopulationManager::getCitizens() const {
    return citizens;
}

void PopulationManager::checkCitizenStates() {
    for (auto& citizen : citizens) {
        // Only allow job and income-related state changes for citizens 18 and older
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

void PopulationManager::updateCitizensAge() {
    for (auto& citizen : citizens) {
        // Increment the citizen's age
        citizen->incrementAge();
        
        // If the citizen has turned 18 and has no satisfaction strategy
        if (citizen->getAge() == 18 ) {
            // Randomly assign a predefined satisfaction strategy
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

void PopulationManager::manageRelationships() {
    // Temporary vector to store new citizens to be added after the main loop
    std::vector<std::shared_ptr<Citizen>> newCitizens;

    // Iterate through the existing citizens without modifying the vector
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

        // If married, add a child after a certain duration
        if (citizen->getRelationshipStatus() == "Married" && citizen->getMarriageDuration() >= 3) {
            // Create a new child as a MaleCitizen or FemaleCitizen
            std::shared_ptr<Citizen> child;
            if (std::rand() % 2 == 0) {
                child = std::make_shared<MaleCitizen>("RandomMale", 0, "Single", "Unemployed");
            } else {
                child = std::make_shared<FemaleCitizen>("RandomFemale", 0, "Single", "Unemployed");
            }

            if (child) {
                std::cout << "Child " << child->getName() << " created successfully.\n";
                newCitizens.push_back(child);  // Add child to temporary vector
            }
            citizen->resetMarriageDuration();
            std::cout << citizen->getName() << " has a new child.\n";
            citizen->addChild();
        }

        if (citizen->getRelationshipStatus() == "Married") {
            citizen->incrementMarriageDuration();
        }
    }

    // Add all new citizens to the main citizens vector after the loop completes
    citizens.insert(citizens.end(), newCitizens.begin(), newCitizens.end());
}


void PopulationManager::updateCitizensSatisfaction() {
    for (auto& citizen : citizens) {
        // Only update satisfaction for citizens above a certain age, if required
        if (citizen->getAge() >= 18) {
            citizen->updateSatisfaction();
        }
    }
}


