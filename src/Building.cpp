/**
 * @file Building.cpp
 * @brief Implementation of the Building class.
 * 
 * This file contains the implementation of the Building class, which provides methods
 * to manage various properties and operations of a building.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Building.h
 */

#include "Building.h"
#include <iostream>

/**
 * @brief Primary constructor for Building.
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
Building::Building(const std::string& name, float area, int floors, int capacity,
                   float satisfactionImpact, float growthImpact, float consumption)
    : name(name), area(area), floors(floors), capacity(capacity),
      citizenSatisfaction(satisfactionImpact), economicGrowth(growthImpact),
      resourceConsumption(consumption) {}

/**
 * @brief Secondary constructor for Building.
 * 
 * Initializes the building with default values or setup values specific to the "Builder" type.
 * 
 * @param Builder An integer representing the Builder type.
 */
Building::Building(int Builder) {
    // This constructor might initialize certain defaults or setup values specific to the "Builder" type.
    // Example defaults if using Builder (adjust as needed):
    this->name = "Default Building";
    this->area = 500.0f;
    this->floors = 2;
    this->capacity = 100;
    this->citizenSatisfaction = 10.0f;
    this->economicGrowth = 5.0f;
    this->resourceConsumption = 2.0f;
}

// Getters
/**
 * @brief Gets the citizen satisfaction impact of the building.
 * @return The citizen satisfaction impact.
 */
float Building::getSatisfaction() const { return citizenSatisfaction; }

/**
 * @brief Gets the economic growth impact of the building.
 * @return The economic growth impact.
 */
float Building::getEconomicGrowth() const { return economicGrowth; }

/**
 * @brief Gets the resource consumption of the building.
 * @return The resource consumption.
 */
float Building::getResourceConsumption() const { return resourceConsumption; }

/**
 * @brief Adds a job to the building.
 * @param job A shared pointer to the job to be added.
 */
void Building::addJob(std::shared_ptr<Jobs> job) {
    jobs.push_back(job);
}

/**
 * @brief Lists all jobs in the building.
 */
void Building::listJobs() const {
    for (const auto& job : jobs) {
        job->displayJobInfo();  // Display job information for each job
    }
}

/**
 * @brief Hires an employee for a job if available.
 * @param jobTitle The title of the job.
 * @return True if the employee was hired, false otherwise.
 */
bool Building::hireEmployee(const std::string& jobTitle) {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle && !job->isOccupied()) {
            job->hireEmployee();
            return true;
        }
    }
    return false;  // Job not found or no positions available
}

/**
 * @brief Releases an employee from a job.
 * @param jobTitle The title of the job.
 */
void Building::releaseEmployee(const std::string& jobTitle) {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle) {
            job->releaseEmployee();
            break;
        }
    }
}

/**
 * @brief Provides access to an available job.
 * @return A shared pointer to the first unoccupied job, or nullptr if no available jobs.
 */
std::shared_ptr<Jobs> Building::getAvailableJob() {
    for (auto& job : jobs) {
        if (!job->isOccupied()) {
            return job;  // Return the first unoccupied job
        }
    }
    return nullptr;  // No available jobs
}

/**
 * @brief Displays specific job information by title.
 * @param jobTitle The title of the job.
 */
void Building::displayJobInfo(const std::string& jobTitle) const {
    for (const auto& job : jobs) {
        if (job->getTitle() == jobTitle) {
            job->displayJobInfo();
            break;
        }
    }
}

/**
 * @brief Gets the list of jobs in the building.
 * @return A constant reference to the vector of shared pointers to jobs.
 */
const std::vector<std::shared_ptr<Jobs>>& Building::getJobs() const {
    return jobs;
}

// Setters
/**
 * @brief Sets the name of the building.
 * @param name The name of the building.
 */
void Building::setName(const std::string& name) { this->name = name; }

/**
 * @brief Gets the name of the building.
 * @return The name of the building.
 */
std::string Building::getName() const { return name; }

/**
 * @brief Collects taxes from the building.
 * @param taxType Pointer to the TaxType object.
 * @return The amount of tax collected.
 */
double Building::payTaxes(TaxType* taxType) {
    // Placeholder for tax collection logic
    taxType->calculateTax(0.0);
    return 0.0;
}

/**
 * @brief Undoes the tax collection from the building.
 */
void Building::undoCollectTaxes() {
    // Placeholder for undoing tax collection logic
}

/**
 * @brief Adds a citizen to the building.
 * @param citizen Pointer to the Citizen object.
 */
void Building::addCitizen(Citizen* citizen) {
    // Placeholder for adding citizens to a building
}

/**
 * @brief Adds a business to the building.
 * @param business A shared pointer to the Business object.
 */
void Building::addBusiness(std::shared_ptr<Business> business) {
    // Placeholder for adding businesses to a building
}