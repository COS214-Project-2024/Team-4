// CityService.h
#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include <string>

class CityService {
private:
    std::string serviceName;  // Name of the city service
    double budgetAllocated;   // Budget allocated to the city service

public:
    // Constructor to initialize a city service with a name and budget
    CityService(const std::string& name, double budget)
        : serviceName(name), budgetAllocated(budget) {}

    // Updates the budget allocated to the city service
    void updateBudget(double amount);

    // Provides the city service
    void provideService();

    // Gets the budget allocated to the city service
    // Returns the current budget allocated
    double getBudgetAllocated() const;
};

#endif // CITYSERVICE_H
