#include "CityService.h"
#include <iostream>

using namespace std;

// Default constructor
CityService::CityService() : serviceName("Default Service"), budgetAllocated(0.0) {}

// Constructor for CityService
// Initializes the city service with a name and initial budget
CityService::CityService(const std::string& name, double initialBudget)
    : serviceName(name), budgetAllocated(initialBudget) {}

// Updates the budget allocated to the city service
// Adds the specified amount to the current budget and prints the new budget
void CityService::updateBudget(double amount) {
    budgetAllocated += amount;
    cout << "Budget updated. New budget: " << budgetAllocated << endl;
}

// Provides the city service
// Prints a message indicating the service being provided
void CityService::provideService() {
    cout << "Providing service: " << serviceName << endl;
}

// Gets the budget allocated to the city service
// Returns the current budget allocated
double CityService::getBudgetAllocated() const {
    return budgetAllocated;
}

// Sets the name of the city service
void CityService::setServiceName(const std::string& name) {
    serviceName = name;
}

// Gets the name of the city service
std::string CityService::getServiceName() const {
    return serviceName;
}

// Prints the details of the city service
void CityService::printDetails() const {
    cout << "City Service Details:" << endl;
    cout << "Service Name: " << serviceName << endl;
    cout << "Budget Allocated: " << budgetAllocated << endl;
}

// Checks if the service is within budget
bool CityService::isWithinBudget(double amount) const {
    return budgetAllocated >= amount;
}

// Allocates additional budget to the city service
// Ensures the allocation does not exceed a specified limit
void CityService::allocateAdditionalBudget(double amount, double limit) {
    if (amount > limit) {
        throw std::invalid_argument("Amount exceeds the specified limit");
    }
    updateBudget(amount);
}

// Reduces the budget allocated to the city service
// Ensures the reduction does not result in a negative budget
void CityService::reduceBudget(double amount) {
    if (amount > budgetAllocated) {
        throw std::invalid_argument("Amount exceeds the current budget");
    }
    budgetAllocated -= amount;
    cout << "Budget reduced. New budget: " << budgetAllocated << endl;
}