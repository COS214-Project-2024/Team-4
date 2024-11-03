#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "GovObserver.h"
#include "CityService.h"
#include "Policy.h"
#include <vector>
#include <string>

class Government {

private:
    double taxRate;                      // Tax rate applied by the government
    double budget;                       // Budget of the government
    std::string governmentName;          // Name of the government
    std::vector<GovObserver*> observers; // List of observers

public:
    // Constructor
    // Initializes the government with a name
    Government(std::string name);

    // Sets the tax rate for the government
    void setTax(double rate);

    // Gets the current tax rate
    double getTaxRate() const;

    // Notifies citizens of changes
    void notifyCitizen();

    // Notifies businesses of changes
    void notifyBusinesses();

    // Notifies services of changes
    void notifyServices();

    // Allocates budget to a city service
    void allocateBudget(CityService& service, double amount);

    // Reverts the budget allocation to a city service
    void revertBudgetAllocation(CityService& service, double amount);

    // Enforces a policy in the government
    void enforcePolicy(Policy policy);

    // Updates the population of the government
    void update(int newPopulation);

    // Collects taxes based on the tax rate
    double collectTaxes();

    // Refunds collected taxes
    void refundTaxes(double amount);

    // Registers an observer to the government
    void registerObserver(GovObserver* observer);

    // Unregisters an observer from the government
    void unregisterObserver(GovObserver* observer);

    // Notifies all registered observers of changes
    void notifyObservers();

    // Gets the current budget
    double getBudget() const;
};

#endif