#ifndef BUILDINGMANAGER_H
#define BUILDINGMANAGER_H

#include <vector>
#include <string>
#include "Building.h"
#include "Citizen.h"
#include "Jobs.h"
#include <memory>

class BuildingManager {
private:
    std::vector<std::shared_ptr<Building>> buildings;   // Collection of buildings managed by the mediator
    std::vector<Citizen*> citizens;     // Collection of citizens managed by the mediator

public:
    BuildingManager(const std::vector<std::shared_ptr<Building>>& buildingList);
    // Register a building with the manager
    void addBuilding(Building* building);

    std::vector<std::shared_ptr<Building>> getBuildings() ;
    // Register a citizen with the manager
    void addCitizen(Citizen* citizen);

    // Assign a job to a citizen in a specific building
    bool assignJobToCitizen(const std::string& jobTitle, Citizen* citizen, Building* building);

    // Release a citizen from their current job
    void releaseCitizenFromJob(Citizen* citizen);

    // List all jobs available in a specific building
    void listAllJobsInBuilding(const Building* building) const;

    std::shared_ptr<Jobs> findAvailableJob();
};

#endif
