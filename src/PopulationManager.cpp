#include "PopulationManager.h"
#include "Citizen.h"

void PopulationManager::addCitizen(std::shared_ptr<Citizen> citizen) {
    citizens.push_back(citizen);
    citizen->addObserver(this);  // Register this PopulationManager as an observer
}

void PopulationManager::update(Citizen* citizen) {
    // Logic to handle updates when a citizen changes
    // For example, respond to job status changes, health updates, etc.
}

