/**
 * @file PopulationManager.h
 * @brief Definition of the PopulationManager class.
 * @version 1.0
 * 
 * This file contains the definition of the PopulationManager class, which manages
 * the population of citizens, including adding, removing, and updating citizens.
 */

#ifndef POPULATIONMANAGER_H
#define POPULATIONMANAGER_H

#include <vector>
#include <memory>
#include <atomic>
#include <mutex>
#include "Citizen.h"
#include "JobSatisfactionStrategy.h"
#include "HousingSatisfactionStrategy.h"

class BuildingManager;

/**
 * @class PopulationManager
 * @brief Manages the population of citizens.
 * 
 * The PopulationManager class manages the population of citizens, including adding, removing,
 * and updating citizens. It also handles job assignments, relationship management, and satisfaction updates.
 */
class PopulationManager {
private:
    std::vector<std::shared_ptr<Citizen>> citizens; ///< List of citizens in the population
    std::atomic<bool> programRunning;   ///< Atomic flag for program status
    std::mutex citizenMutex;            ///< Mutex for thread-safe access to citizens
    std::shared_ptr<JobSatisfactionStrategy> jobSatisfaction; ///< Job satisfaction strategy
    std::shared_ptr<HousingSatisfactionStrategy> housingSatisfaction; ///< Housing satisfaction strategy

public:
    /**
     * @brief Constructor for PopulationManager.
     * 
     * Initializes the PopulationManager with job and housing satisfaction strategies.
     */
    PopulationManager();

    /**
     * @brief Finds jobs for unemployed citizens using the BuildingManager.
     * @param buildingManager The BuildingManager to use for finding jobs.
     */
    void findJobsForUnemployedCitizens(BuildingManager& buildingManager);

    /**
     * @brief Updates the age of all citizens each cycle.
     */
    void updateCitizensAge();

    /**
     * @brief Adds a citizen to the population.
     * @param citizen The citizen to be added.
     */
    void addCitizen(std::shared_ptr<Citizen> citizen);

    /**
     * @brief Checks and updates citizens' states based on satisfaction levels.
     */
    void checkCitizenStates();

    /**
     * @brief Simulates population growth randomly by adding or removing citizens.
     */
    void simulatePopulationGrowth();

    /**
     * @brief Removes citizens who are leaving the city.
     */
    void removeLeavingCitizens();

    /**
     * @brief Manages relationships between citizens.
     */
    void manageRelationships();

    /**
     * @brief Gets the current population count.
     * @return The current population count.
     */
    int getPopulation();

    /**
     * @brief Gets the list of all citizens.
     * @return A vector of shared pointers to all citizens.
     */
    const std::vector<std::shared_ptr<Citizen>>& getCitizens() const;

    /**
     * @brief Updates satisfaction for all eligible citizens.
     */
    void updateCitizensSatisfaction();

private:
    /**
     * @brief Adds a random citizen to the population.
     */
    void addRandomCitizen();

    /**
     * @brief Removes a random citizen from the population.
     */
    void removeRandomCitizen();
};

#endif // POPULATIONMANAGER_H