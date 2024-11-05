#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Jobs.h"
#include "Citizen.h"
#include "Business.h"

/**
 * @file Building.h
 * @brief Declaration of the Building class.
 * 
 * This file contains the declaration of the Building class, which provides methods
 * to manage various properties and operations of a building.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Building.cpp
 */

/**
 * @class Building
 * @brief Provides methods to manage various properties and operations of a building.
 * 
 * The Building class provides methods to manage various properties and operations of a building.
 * It includes methods to set and get the name, area, number of floors, capacity, citizen satisfaction,
 * economic growth, and resource consumption of the building. It also includes methods to manage jobs,
 * collect taxes, and add citizens and businesses.
 * 
 * @version 1.0
 * @date 04/10/2024
 */
class Building {
protected:
    std::string name;                   ///< Name of the building
    float area;                         ///< Area of the building
    int floors;                         ///< Number of floors in the building
    int capacity;                       ///< Capacity of the building
    float citizenSatisfaction;          ///< Citizen satisfaction impact of the building
    float economicGrowth;               ///< Economic growth impact of the building
    float resourceConsumption;          ///< Resource consumption of the building
    std::vector<std::shared_ptr<Jobs>> jobs;  ///< Collection of jobs as shared pointers

public:
    /**
     * @brief Main constructor for setting attributes directly.
     * 
     * Initializes the building with the given properties.
     * 
     * @param name The name of the building.
     * @param area The area of the building.
     * @param floors The number of floors in the building.
     * @param capacity The capacity of the building.
     * @param satisfactionImpact The impact on citizen satisfaction.
     * @param growthImpact The impact on economic growth.
     * @param consumption The resource consumption of the building.
     */
    Building(const std::string& name, float area, int floors, int capacity,
             float satisfactionImpact, float growthImpact, float consumption);

    /**
     * @brief Alternative constructor using an integer parameter, potentially for Builder pattern integration.
     * 
     * Initializes the building with default values or setup values specific to the "Builder" type.
     * 
     * @param Builder An integer representing the Builder type.
     */
    Building(int Builder);

    // Setters and getters
    /**
     * @brief Sets the name of the building.
     * @param name The name of the building.
     */
    void setName(const std::string& name);

    /**
     * @brief Gets the name of the building.
     * @return The name of the building.
     */
    std::string getName() const;

    /**
     * @brief Constructs the building.
     */
    virtual void construct() = 0;

    /**
     * @brief Virtual destructor for Building.
     */
    virtual ~Building() = default;

    /**
     * @brief Gets the citizen satisfaction impact of the building.
     * @return The citizen satisfaction impact.
     */
    float getSatisfaction() const;

    /**
     * @brief Gets the economic growth impact of the building.
     * @return The economic growth impact.
     */
    float getEconomicGrowth() const;

    /**
     * @brief Gets the resource consumption of the building.
     * @return The resource consumption.
     */
    float getResourceConsumption() const;

    /**
     * @brief Updates the impacts of the building.
     */
    virtual void updateImpacts() = 0;

    /**
     * @brief Gets the type of the building.
     * @return The type of the building.
     */
    virtual std::string getType() const = 0;

    // Job management methods
    /**
     * @brief Adds a job to the building.
     * @param job A shared pointer to the job to be added.
     */
    void addJob(std::shared_ptr<Jobs> job);

    /**
     * @brief Lists all jobs in the building.
     */
    void listJobs() const;

    /**
     * @brief Hires an employee for a job if available.
     * @param jobTitle The title of the job.
     * @return True if the employee was hired, false otherwise.
     */
    bool hireEmployee(const std::string& jobTitle);

    /**
     * @brief Releases an employee from a job.
     * @param jobTitle The title of the job.
     */
    void releaseEmployee(const std::string& jobTitle);

    /**
     * @brief Provides access to an available job.
     * @return A shared pointer to the first unoccupied job, or nullptr if no available jobs.
     */
    std::shared_ptr<Jobs> getAvailableJob();

    /**
     * @brief Displays specific job information by title.
     * @param jobTitle The title of the job.
     */
    void displayJobInfo(const std::string& jobTitle) const;

    /**
     * @brief Gets the list of jobs in the building.
     * @return A constant reference to the vector of shared pointers to jobs.
     */
    const std::vector<std::shared_ptr<Jobs>>& getJobs() const;

    // Tax management methods
    /**
     * @brief Collects taxes from the building.
     * @param taxType Pointer to the TaxType object.
     * @return The amount of tax collected.
     */
    virtual double payTaxes(TaxType* taxType) = 0;

    /**
     * @brief Undoes the tax collection from the building.
     */
    virtual void undoCollectTaxes() = 0;

    // Citizen and business management methods
    /**
     * @brief Adds a citizen to the building.
     * @param citizen Pointer to the Citizen object.
     */
    virtual void addCitizen(Citizen* citizen) = 0;

    /**
     * @brief Adds a business to the building.
     * @param business A shared pointer to the Business object.
     */
    virtual void addBusiness(std::shared_ptr<Business> business) = 0;

private:
    /**
     * @brief Calculates the satisfaction impact of the building.
     */
    virtual void calculateSatisfactionImpact() = 0;

    /**
     * @brief Calculates the economic impact of the building.
     */
    virtual void calculateEconomicImpact() = 0;

    /**
     * @brief Calculates the resource consumption of the building.
     */
    virtual void calculateResourceConsumption() = 0;
};

#endif // BUILDING_H