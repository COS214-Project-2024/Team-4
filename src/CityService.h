#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include <string>

/**
 * @file CityService.h
 * @brief Declaration of the CityService class.
 * 
 * This file contains the declaration of the CityService class, which represents a city service
 * and includes methods to manage its budget and provide services.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see CityService.cpp
 */

/**
 * @class CityService
 * @brief Represents a city service with budget management and service provision capabilities.
 * 
 * The CityService class represents a city service with budget management and service provision capabilities.
 * It includes methods to manage its budget and provide services.
 * 
 * @version 1.0
 * @date 04/10/2024
 */
class CityService {

private:
    std::string serviceName;  ///< Name of the city service
    double budgetAllocated;   ///< Budget allocated to the city service

public:
    /**
     * @brief Default constructor for CityService.
     * 
     * Initializes the city service with default values.
     */
    CityService();

    /**
     * @brief Constructor for CityService.
     * 
     * Initializes the city service with a name and initial budget.
     * 
     * @param name The name of the city service.
     * @param initialBudget The initial budget allocated to the city service.
     */
    CityService(const std::string& name, double initialBudget);

    /**
     * @brief Updates the budget allocated to the city service.
     * 
     * Adds the specified amount to the current budget.
     * 
     * @param amount The amount to add to the budget.
     */
    void updateBudget(double amount);

    /**
     * @brief Provides the city service.
     * 
     * Prints a message indicating the service being provided.
     */
    void provideService();

    /**
     * @brief Gets the budget allocated to the city service.
     * @return The current budget allocated.
     */
    double getBudgetAllocated() const;

    /**
     * @brief Sets the name of the city service.
     * @param name The name of the city service.
     */
    void setServiceName(const std::string& name);

    /**
     * @brief Gets the name of the city service.
     * @return The name of the city service.
     */
    std::string getServiceName() const;

    /**
     * @brief Prints the details of the city service.
     */
    void printDetails() const;

    /**
     * @brief Checks if the service is within budget.
     * @param amount The amount to check against the budget.
     * @return True if the service is within budget, false otherwise.
     */
    bool isWithinBudget(double amount) const;

    /**
     * @brief Allocates additional budget to the city service.
     * 
     * Ensures the allocation does not exceed a specified limit.
     * 
     * @param amount The amount to allocate.
     * @param limit The maximum limit for the allocation.
     * @throws std::invalid_argument if the amount exceeds the specified limit.
     */
    void allocateAdditionalBudget(double amount, double limit);

    /**
     * @brief Reduces the budget allocated to the city service.
     * 
     * Ensures the reduction does not result in a negative budget.
     * 
     * @param amount The amount to reduce from the budget.
     * @throws std::invalid_argument if the amount exceeds the current budget.
     */
    void reduceBudget(double amount);
};

#endif // CITYSERVICE_H