#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include <string>

class CityService {

private:
    std::string serviceName;  // Name of the city service
    double budgetAllocated;   // Budget allocated to the city service

public:
    // Updates the budget allocated to the city service
    void updateBudget(double amount);

    // Provides the city service
    void provideService();

    // Gets the budget allocated to the city service
    // Returns the current budget allocated
    double getBudgetAllocated() const;
};

#endif