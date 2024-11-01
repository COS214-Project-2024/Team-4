// PopulationManager.h

#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include "CitizenObserver.h"
#include <vector>
#include <memory>
#include <atomic>
#include "Citizen.h"

class PopulationManager : public CitizenObserver {
private:
    std::vector<std::shared_ptr<Citizen>> citizens;
    std::atomic<bool> programRunning; // Atomic flag for program status
public:
    PopulationManager();
    void addCitizen(std::shared_ptr<Citizen> citizen); 
    void update(Citizen* citizen) override;              // Responds to Citizen state changes
    void checkCitizenStates();                           // Periodic state updater
    void simulatePopulationGrowth();                     // Simulate random growth
    void removeLeavingCitizens();                        // Remove citizens in LeavingCityState
    void manageRelationships();
    int getPopulation() const;   
    void startRelationshipManager(); // Start the manager in a thread
    void stopRelationshipManager();  // Safely stop the manager  
    void startSatisfactionUpdater();     // Start satisfaction updates in a loop
    void stopSatisfactionUpdater();      // Stop the update loop
    void updateCitizensSatisfaction();   // Update satisfaction for all citizens                      // Utility function to get population count
private:
    void addRandomCitizen();                             // Add citizen randomly
    void removeRandomCitizen();                          // Remove citizen randomly
};

#endif // POPULATIONMANAGER_H




