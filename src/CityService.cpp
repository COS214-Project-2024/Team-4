/**
 * @file CityService.cpp
 * @brief Implementation of the CityService class.
 *
 * This file contains the implementation of the CityService class which manages city services.
 * @date 2024-11-04
 * @version 1.0
 */

#include "CityService.h"
#include <iostream>

using namespace std;

// Default constructor
/**
 * @brief Default constructor for CityService.
 *
 * Initializes the city service with default values.
 */
CityService::CityService() : serviceName("Default Service"), budgetAllocated(0.0) {}

// Constructor for CityService
/**
 * @brief Constructor for CityService.
 *
 * Initializes the city service with a name and initial budget.
 * 
 * @param name The name of the city service.
 * @param initialBudget The initial budget allocated to the city service.
 */
CityService::CityService(const std::string& name, double initialBudget)
    : serviceName(name), budgetAllocated(initialBudget) {}

// Updates the budget allocated to the city service
/**
 * @brief Updates the budget allocated to the city service.
 *
 * Adds the specified amount to the current budget and prints the new budget.
 * 
 * @param amount The amount to add to the current budget.
 */
void CityService::updateBudget(double amount) {
    budgetAllocated += amount;
    cout << "Budget updated. New budget: " << budgetAllocated << endl;
}

// Provides the city service
/**
 * @brief Provides the city service.
 *
 * Prints a message indicating the service being provided.
 */
void CityService::provideService() {
    cout << "Providing service: " << serviceName << endl;
}

// Gets the budget allocated to the city service
/**
 * @brief Gets the budget allocated to the city service.
 *
 * @return The current budget allocated.
 */
double CityService::getBudgetAllocated() const {
    return budgetAllocated;
}

// Sets the name of the city service
/**
 * @brief Sets the name of the city service.
 * 
 * @param name The new name of the city service.
 */
void CityService::setServiceName(const std::string& name) {
    serviceName = name;
}

// Gets the name of the city service
/**
 * @brief Gets the name of the city service.
 * 
 * @return The name of the city service.
 */
std::string CityService::getServiceName() const {
    return serviceName;
}

// Prints the details of the city service
/**
 * @brief Prints the details of the city service.
 */
void CityService::printDetails() const {
    cout << "City Service Details:" << endl;
    cout << "Service Name: " << serviceName << endl;
    cout << "Budget Allocated: " << budgetAllocated << endl;
}