#include "PopulationManager.h"
#include "Citizen.h"
#include <iostream>

void PopulationManager::addCitizen(std::shared_ptr<Citizen> citizen) {
    citizens.push_back(citizen);
    citizen->addObserver(this);  // Register this PopulationManager as an observer
}

void PopulationManager::update(Citizen* citizen) {
    // Example response to a Citizen update
    std::cout << "PopulationManager notified: Citizen " << citizen->getName() 
              << " has been updated. Current satisfaction: " << citizen->getSatisfactionLevel() 
              << "\n";
}

