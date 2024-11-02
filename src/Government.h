#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "GovObserver.h"
#include "CityService.h"
#include "Policy.h"
#include <vector>
#include <string>

class Government {

private:
    double taxRate;
    double budget;
    std::string governmentName;
    std::vector<GovObserver*> observers;

public:
    Government(std::string name);

    void setTax(double rate);
    double getTaxRate() const;
    void notifyCitizen();
    void notifyBusinesses();
    void notifyServices();
    void allocateBudget(CityService& service, double amount);
    void revertBudgetAllocation(CityService& service, double amount);
    void enforcePolicy(Policy policy);
    void update(int newPopulation);
    double collectTaxes();
    void refundTaxes(double amount);

    void registerObserver(GovObserver* observer);
    void unregisterObserver(GovObserver* observer);
    void notifyObservers();
};

#endif