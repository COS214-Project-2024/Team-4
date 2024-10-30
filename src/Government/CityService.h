#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include <string>

class CityService {

private:
    std::string serviceName;
    double budgetAllocated;

public:
    void updateBudget(double amount);
    void provideService();
    double getBudgetAllocated() const; // Add this getter method
};

#endif