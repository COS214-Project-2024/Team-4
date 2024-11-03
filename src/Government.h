// Government.h

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include <memory>
#include "CityService.h"
#include "Policy.h"
#include "GovObserver.h"

class Government {
public:
    Government(std::string name);
    void setTax(double rate);
    double getTaxRate() const;
    void notifyCitizen();
    void notifyBusinesses();
    void notifyServices();
    void allocateBudget(CityService& service, double amount);
    void revertBudgetAllocation(CityService& service, double amount);
    void enforcePolicy(Policy* policy);
    void update(int newPopulation);
    void refundTaxes(double amount);
    void registerObserver(GovObserver* observer);
    void unregisterObserver(GovObserver* observer);
    void notifyObservers();
    void addTaxesToBudget(double amount);

private:
    std::string governmentName;
    double taxRate;
    double budget;
    std::vector<GovObserver*> observers;
};

#endif // GOVERNMENT_H