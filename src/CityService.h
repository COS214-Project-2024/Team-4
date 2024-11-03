#ifndef CITYSERVICE_H
#define CITYSERVICE_H

#include <string>

class CityService {

private:
    std::string serviceName;  // Name of the city service
    double budgetAllocated;   // Budget allocated to the city service

public:
    // Default constructor
    CityService(); // Add this line

    // Constructor
    CityService(const std::string& name, double initialBudget);

    // Updates the budget allocated to the city service
    void updateBudget(double amount);

    // Provides the city service
    void provideService();

    // Gets the budget allocated to the city service
    // Returns the current budget allocated
    double getBudgetAllocated() const;

    // Sets the name of the city service
    void setServiceName(const std::string& name);

    // Gets the name of the city service
    std::string getServiceName() const;

    // Prints the details of the city service
    void printDetails() const;

    // Checks if the service is within budget
    bool isWithinBudget(double amount) const;

    // Allocates additional budget to the city service
    void allocateAdditionalBudget(double amount, double limit);

    // Reduces the budget allocated to the city service
    void reduceBudget(double amount);
};

#endif