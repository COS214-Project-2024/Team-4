/**
 * @file BuildingManager.h
 * @brief Definition of the BuildingManager class.
 * 
 * This file contains the definition of the BuildingManager class, which manages buildings and citizens.
 * It includes methods to add buildings and citizens, assign jobs to citizens, release citizens from jobs,
 * list all jobs in a building, and find available jobs across all buildings.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city buildings and their properties.
 */

#ifndef BUILDINGMANAGER_H
#define BUILDINGMANAGER_H

#include <vector>
#include <string>
#include "Building.h"
#include "Citizen.h"
#include "Jobs.h"
#include <memory>

/**
 * @class BuildingManager
 * @brief Manages buildings and citizens.
 * 
 * This class provides methods to add buildings and citizens, assign jobs to citizens, release citizens from jobs,
 * list all jobs in a building, and find available jobs across all buildings.
 */
class BuildingManager {
private:
    std::vector<std::shared_ptr<Building>> buildings; ///< Collection of buildings managed by the mediator
    std::vector<Citizen*> citizens; ///< Collection of citizens managed by the mediator

public:
    /**
     * @brief Constructs a new BuildingManager object.
     * 
     * @param buildingList A list of buildings to be managed.
     */
    BuildingManager(const std::vector<std::shared_ptr<Building>>& buildingList);

    /**
     * @brief Adds a building to the list of managed buildings.
     * 
     * @param building Pointer to the building to be added.
     */
    void addBuilding(Building* building);

    /**
     * @brief Gets the list of managed buildings.
     * 
     * @return std::vector<std::shared_ptr<Building>> The list of managed buildings.
     */
    std::vector<std::shared_ptr<Building>> getBuildings();

    /**
     * @brief Adds a citizen to the list of managed citizens.
     * 
     * @param citizen Pointer to the citizen to be added.
     */
    void addCitizen(Citizen* citizen);

    /**
     * @brief Assigns a job to a citizen in a specific building.
     * 
     * @param jobTitle The title of the job to be assigned.
     * @param citizen Pointer to the citizen to be assigned the job.
     * @param building Pointer to the building where the job is located.
     * @return true if the job was successfully assigned to the citizen.
     * @return false if the job could not be assigned.
     */
    bool assignJobToCitizen(const std::string& jobTitle, Citizen* citizen, Building* building);

    /**
     * @brief Releases a citizen from their current job.
     * 
     * @param citizen Pointer to the citizen to be released from their job.
     */
    void releaseCitizenFromJob(Citizen* citizen);

    /**
     * @brief Lists all jobs available in a specific building.
     * 
     * @param building Pointer to the building whose jobs are to be listed.
     */
    void listAllJobsInBuilding(const Building* building) const;

    /**
     * @brief Finds an available job across all buildings.
     * 
     * @return std::shared_ptr<Jobs> A shared pointer to an available job, or nullptr if no jobs are available.
     */
    std::shared_ptr<Jobs> findAvailableJob();
};

#endif // BUILDINGMANAGER_H