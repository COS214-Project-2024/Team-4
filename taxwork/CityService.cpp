#include "CityService.h"
#include <iostream>

using namespace std;

void CityService::updateBudget(double amount) {
    budgetAllocated += amount;
    cout << "Budget updated. New budget: " << budgetAllocated << endl;
}

void CityService::provideService() {
    cout << "Providing service: " << serviceName << endl;
}

double CityService::getBudgetAllocated() const {
    return budgetAllocated;
}