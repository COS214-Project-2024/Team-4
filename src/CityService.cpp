/**
 * @file CityService.cpp
 * @brief Implementation of the CityService class.
 * 
 * This file contains the implementation of the CityService class, which represents a city service
 * and includes methods to manage its budget and provide services.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see CityService.h
 */

#include "CityService.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor for CityService.
 * 
 * Initializes the city service with default values.
 */
CityService::CityService() : serviceName("Default Service"), budgetAllocated(0.0) {}

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

/**
 * @brief Updates the budget allocated to the city service.
 * 
 * Adds the specified amount to the current budget and prints the new budget.
 * 
 * @param amount The amount to add to the budget.
 */
void CityService::updateBudget(double amount) {
    budgetAllocated += amount;
    cout << "Budget updated. New budget: " << budgetAllocated << endl;
}

/**
 * @brief Provides the city service.
 * 
 * Prints a message indicating the service being provided.
 */
void CityService::provideService() {
    cout << "Providing service: " << serviceName << endl;
}

/**
 * @brief Gets the budget allocated to the city service.
 * @return The current budget allocated.
 */
double CityService::getBudgetAllocated() const {
    return budgetAllocated;
}

/**
 * @brief Sets the name of the city service.
 * @param name The name of the city service.
 */
void CityService::setServiceName(const std::string& name) {
    serviceName = name;
}

/**
 * @brief Gets the name of the city service.
 * @return The name of the city service.
 */
std::string CityService::getServiceName() const {
    return serviceName;
}

/**
 * @brief Prints the details of the city service.
 */
void CityService::printDetails() const {
    cout << "City Service Details:" << endl;
    cout << "Service Name: " << serviceName << endl;
    cout << "Budget Allocated: " << budgetAllocated << endl;
}

/**
 * @brief Checks if the service is within budget.
 * @param amount The amount to check against the budget.
 * @return True if the service is within budget, false otherwise.
 */
bool CityService::isWithinBudget(double amount) const {
    return budgetAllocated >= amount;
}

/**
 * @brief Allocates additional budget to the city service.
 * 
 * Ensures the allocation does not exceed a specified limit.
 * 
 * @param amount The amount to allocate.
 * @param limit The maximum limit for the allocation.
 * @throws std::invalid_argument if the amount exceeds the specified limit.
 */
void CityService::allocateAdditionalBudget(double amount, double limit) {
    if (amount > limit) {
        throw std::invalid_argument("Amount exceeds the specified limit");
    }
    updateBudget(amount);
}

/**
 * @brief Reduces the budget allocated to the city service.
 * 
 * Ensures the reduction does not result in a negative budget.
 * 
 * @param amount The amount to reduce from the budget.
 * @throws std::invalid_argument if the amount exceeds the current budget.
 */
void CityService::reduceBudget(double amount) {
    if (amount > budgetAllocated) {
        throw std::invalid_argument("Amount exceeds the current budget");
    }
    budgetAllocated -= amount;
    cout << "Budget reduced. New budget: " << budgetAllocated << endl;
}