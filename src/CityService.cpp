#include "CityService.h"
#include <iostream>

using namespace std;

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