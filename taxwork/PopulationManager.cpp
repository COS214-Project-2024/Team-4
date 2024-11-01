#include "PopulationManager.h"
#include "Citizen.h"
#include "CitizenState.h"
#include "EmployedState.h"
#include "UnemployedState.h"
#include "SatisfiedState.h"
#include "UnsatisfiedState.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib> // For random relationship progression
// PopulationManager.cpp

#include "PopulationManager.h"
#include "Citizen.h"
#include "LeavingCityState.h"
#include <algorithm>
#include <random>
#include <ctime>

PopulationManager::PopulationManager() {
    std::srand(std::time(nullptr)); // Seed for randomness
}

void PopulationManager::addCitizen(std::shared_ptr<Citizen> citizen) {
    citizens.push_back(citizen);
    citizen->addObserver(this); // Register this PopulationManager as an observer
}

void PopulationManager::update(Citizen* citizen) {
    // Respond to Citizen state changes (e.g., update based on satisfaction)
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

void PopulationManager::addRandomCitizen() {
    auto citizen = std::make_shared<Citizen>("RandomCitizen", std::rand() % 80 + 1, "Single", "Unemployed");
    citizens.push_back(citizen);
    std::cout << "Citizen added. Total population: " << getPopulation() << std::endl;
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

int PopulationManager::getPopulation() const {
    return citizens.size();
}


void PopulationManager::checkCitizenStates() {
    for (auto& citizen : citizens) {
        // Example logic: Switch to UnsatisfiedState if satisfaction is low
        if (citizen->getSatisfactionLevel() < 20) {
            citizen->setState(new UnsatisfiedState());
        } else if (citizen->getSatisfactionLevel() > 80) {
            citizen->setState(new SatisfiedState());
        }
        else if (citizen->getSatisfactionLevel() == 0) {
            citizen->setState(new LeavingCityState()); // Change state if satisfaction is too low
        }
    }
}

PopulationManager::PopulationManager() : programRunning(true) {}

void PopulationManager::startRelationshipManager() {
    // Start manageRelationships in a separate thread
    std::thread relationshipThread(&PopulationManager::manageRelationships, this);
    relationshipThread.detach(); // Detach to let it run independently
}

void PopulationManager::stopRelationshipManager() {
    // Set the flag to false to end the loop
    programRunning = false;
}

void PopulationManager::manageRelationships() {
    while (programRunning) {
        for (auto& citizen : citizens) {
            // Relationship progression logic
            if (citizen->getRelationshipStatus() == "Single" && rand() % 10 == 0) {
                citizen->setRelationshipStatus("Dating");
                std::cout << citizen->getName() << " is now dating.\n";
            } else if (citizen->getRelationshipStatus() == "Dating") {
                if (rand() % 20 == 0) {
                    citizen->setRelationshipStatus("Married");
                    std::cout << citizen->getName() << " just got married!\n";
                } else if (rand() % 15 == 0) {
                    citizen->setRelationshipStatus("Single");
                    std::cout << citizen->getName() << " broke up and is now single.\n";
                }
            }

            // Add a child after a set duration of marriage
            if (citizen->getRelationshipStatus() == "Married" && citizen->getMarriageDuration() >= 3) {
                citizen->addChild();
                citizen->resetMarriageDuration();
                std::cout << citizen->getName() << " has a new child.\n";
            }

            // Update the marriage duration counter if married
            if (citizen->getRelationshipStatus() == "Married") {
                citizen->incrementMarriageDuration();
            }
        }

        // Delay the loop to prevent it from running too fast
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Relationship management stopped.\n";
}

PopulationManager::PopulationManager() : programRunning(true) {}

void PopulationManager::startSatisfactionUpdater() {
    std::thread updaterThread([this]() {
        while (programRunning) {
            updateCitizensSatisfaction();
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Update every 1 second
        }
    });
    updaterThread.detach();
}

void PopulationManager::stopSatisfactionUpdater() {
    programRunning = false;
}

void PopulationManager::updateCitizensSatisfaction() {
    for (auto& citizen : citizens) {
        citizen->updateSatisfaction();
    }
}