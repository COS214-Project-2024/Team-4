#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include <vector>
#include <memory>
#include <atomic>
#include <mutex>
#include "Citizen.h"
#include "JobSatisfactionStrategy.h"
#include "HousingSatisfactionStrategy.h"

class PopulationManager {
private:
    std::vector<std::shared_ptr<Citizen>> citizens;
    std::atomic<bool> programRunning;   // Atomic flag for program status
    std::mutex citizenMutex;            // Mutex for thread-safe access to citizens
    std::shared_ptr<JobSatisfactionStrategy> jobSatisfaction;
    std::shared_ptr<HousingSatisfactionStrategy> housingSatisfaction;

public:
    PopulationManager();
    void findJobsForUnemployedCitizens(BuildingManager& buildingManager);
    void updateCitizensAge();                   // Increment ages
    void addCitizen(std::shared_ptr<Citizen> citizen); // Add citizen to population
    void checkCitizenStates();                  // Periodic state updater
    void simulatePopulationGrowth();            // Simulate random growth
    void removeLeavingCitizens();               // Remove citizens in LeavingCityState
    void manageRelationships();                 // Relationship management
    int getPopulation();                        // Get current population count
    const std::vector<std::shared_ptr<Citizen>>& getCitizens() const;

    void updateCitizensSatisfaction();          // Central satisfaction update loop

private:
    void addRandomCitizen();                    // Add citizen randomly
    void removeRandomCitizen();                 // Remove citizen randomly
};

#endif // POPULATIONMANAGER_H