#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "CitizenObserver.h"
#include <vector>
#include <memory>
#include <atomic>
#include <mutex>
#include "Citizen.h"
#include "JobSatisfactionStrategy.h"
#include "HousingSatisfactionStrategy.h"

class PopulationManager : public CitizenObserver {
private:
    std::vector<std::shared_ptr<Citizen>> citizens;
    std::atomic<bool> programRunning;   // Atomic flag for program status
    std::mutex citizenMutex; 
    std::shared_ptr<JobSatisfactionStrategy> jobSatisfaction;
    std::shared_ptr<HousingSatisfactionStrategy> housingSatisfaction;            // Mutex for thread-safe access to citizens

public:
    PopulationManager();
    void updateCitizensAge();
    void addCitizen(std::shared_ptr<Citizen> citizen);
    void update(Citizen* citizen) override;              // Responds to Citizen state changes
    void checkCitizenStates();                           // Periodic state updater
    void simulatePopulationGrowth();                     // Simulate random growth
    void removeLeavingCitizens();                        // Remove citizens in LeavingCityState
    void manageRelationships();
    int getPopulation();  // Removed `const` to allow locking
    const std::vector<std::shared_ptr<Citizen>>& getCitizens() const;
    // Thread management for relationship and satisfaction updates
    void startRelationshipManager();
    void stopRelationshipManager();
    void startSatisfactionUpdater();
    void stopSatisfactionUpdater();
    void updateCitizensSatisfaction();
    
private:
    void addRandomCitizen();                             // Add citizen randomly
    void removeRandomCitizen();                          // Remove citizen randomly
};

#endif // POPULATIONMANAGER_H






