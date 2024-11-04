/**
 * @file Building.h
 * @brief Definition of the Building class.
 * 
 * This file contains the definition of the Building class, which represents a building
 * with various properties such as name, area, floors, capacity, citizen satisfaction, economic growth,
 * and resource consumption. It includes methods to manage jobs within the building.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city buildings and their properties.
 */

#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include "Jobs.h"

/**
 * @class Building
 * @brief Represents a building with various properties and job management capabilities.
 * 
 * This class provides methods to set and get various properties of a building such as name, area, floors, capacity,
 * citizen satisfaction, economic growth, and resource consumption. It also includes methods to manage jobs within the building.
 */
class Building {
protected:
    std::string name; ///< Name of the building
    float area; ///< Area of the building
    int floors; ///< Number of floors in the building
    int capacity; ///< Capacity of the building
    float citizenSatisfaction; ///< Citizen satisfaction impact of the building
    float economicGrowth; ///< Economic growth impact of the building
    float resourceConsumption; ///< Resource consumption of the building
    std::vector<std::shared_ptr<Jobs>> jobs; ///< Collection of jobs as shared pointers

public:
    /**
     * @brief Main constructor for setting attributes directly.
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
     * @param Builder An integer representing the builder type.
     */
    Building(int Builder);

    /**
     * @brief Sets the name of the building.
     * 
     * @param name The name of the building.
     */
    void setName(const std::string& name);

    /**
     * @brief Gets the name of the building.
     * 
     * @return std::string The name of the building.
     */
    std::string getName() const;

    /**
     * @brief Pure virtual function to construct the building.
     */
    virtual void construct() = 0;

    /**
     * @brief Virtual destructor for the Building class.
     */
    virtual ~Building() = default;

    /**
     * @brief Gets the citizen satisfaction impact of the building.
     * 
     * @return float The citizen satisfaction impact.
     */
    float getSatisfaction() const;

    /**
     * @brief Gets the economic growth impact of the building.
     * 
     * @return float The economic growth impact.
     */
    float getEconomicGrowth() const;

    /**
     * @brief Gets the resource consumption of the building.
     * 
     * @return float The resource consumption.
     */
    float getResourceConsumption() const;

    /**
     * @brief Pure virtual function to update the impacts of the building.
     */
    virtual void updateImpacts() = 0;

    /**
     * @brief Pure virtual function to get the type of the building.
     * 
     * @return std::string The type of the building.
     */
    virtual std::string getType() const = 0;

    /**
     * @brief Adds a job to the building.
     * 
     * @param job A shared pointer to the job to be added.
     */
    void addJob(std::shared_ptr<Jobs> job);

    /**
     * @brief Lists all jobs in the building.
     */
    void listJobs() const;

    /**
     * @brief Hires an employee for a job if available.
     * 
     * @param jobTitle The title of the job to hire for.
     * @return true if the employee was successfully hired.
     * @return false if the job is not available or already occupied.
     */
    bool hireEmployee(const std::string& jobTitle);

    /**
     * @brief Releases an employee from a job.
     * 
     * @param jobTitle The title of the job to release.
     */
    void releaseEmployee(const std::string& jobTitle);

    /**
     * @brief Provides access to an available job.
     * 
     * @return std::shared_ptr<Jobs> A shared pointer to an available job.
     */
    std::shared_ptr<Jobs> getAvailableJob();

    /**
     * @brief Displays job information.
     * 
     * @param jobTitle The title of the job to display information for.
     */
    void displayJobInfo(const std::string& jobTitle) const;

    /**
     * @brief Returns the job list as a const reference.
     * 
     * @return const std::vector<std::shared_ptr<Jobs>>& The job list.
     */
    const std::vector<std::shared_ptr<Jobs>>& getJobs() const;

    /**
     * @brief Pure virtual function to collect taxes from the building.
     * 
     * @param taxType Pointer to the tax type.
     * @return double The amount of taxes collected.
     */
    virtual double payTaxes(TaxType* taxType) = 0;

    /**
     * @brief Pure virtual function to undo collecting taxes from the building.
     */
    virtual void undoCollectTaxes() = 0;

private:
    /**
     * @brief Pure virtual function to calculate the satisfaction impact.
     */
    virtual void calculateSatisfactionImpact() = 0;

    /**
     * @brief Pure virtual function to calculate the economic impact.
     */
    virtual void calculateEconomicImpact() = 0;

    /**
     * @brief Pure virtual function to calculate the resource consumption.
     */
    virtual void calculateResourceConsumption() = 0;
};

#endif // BUILDING_H