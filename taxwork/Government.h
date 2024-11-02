// Government.h

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>
#include <memory>
#include "CityService.h"
#include "Policy.h"
#include "GovObserver.h"

class Government : public std::enable_shared_from_this<Government> {
public:
    Government(std::string name);
    void setTax(double rate);
    double getTaxRate() const;
    void notifyCitizen();
    void notifyBusinesses();
    void notifyServices();
    void allocateBudget(CityService& service, double amount);
    void revertBudgetAllocation(CityService& service, double amount);
    void enforcePolicy(std::shared_ptr<Policy> policy);
    void update(int newPopulation);
    void refundTaxes(double amount);
    void registerObserver(std::shared_ptr<GovObserver> observer);
    void unregisterObserver(std::shared_ptr<GovObserver> observer);
    void notifyObservers();

private:
    std::string governmentName;
    double taxRate;
    double budget;
    std::vector<std::shared_ptr<GovObserver>> observers;
};

#endif // GOVERNMENT_H