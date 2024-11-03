// Government.cpp

#include "Government.h"
#include <iostream>
#include <algorithm>

Government::Government(std::string name) : governmentName(name), taxRate(0.0), budget(0.0) {
    // Constructor implementation
}

void Government::setTax(double rate) {
    taxRate = rate;
    std::cout << "Tax rate set to " << taxRate << "%" << std::endl;
    notifyObservers();
}

double Government::getTaxRate() const {
    return taxRate;
}

void Government::notifyCitizen() {
    std::cout << "Notifying citizens..." << std::endl;
}

void Government::notifyBusinesses() {
    std::cout << "Notifying businesses..." << std::endl;
}

void Government::notifyServices() {
    std::cout << "Notifying services..." << std::endl;
}

void Government::allocateBudget(CityService& service, double amount) {
    budget -= amount;
    service.updateBudget(amount);
    std::cout << "Allocated " << amount << " to service. Remaining budget: " << budget << std::endl;
    notifyObservers();
}

void Government::revertBudgetAllocation(CityService& service, double amount) {
    budget += amount;
    service.updateBudget(-amount);
    std::cout << "Reverted allocation of " << amount << " from service. Remaining budget: " << budget << std::endl;
    notifyObservers();
}

void Government::enforcePolicy(Policy* policy) {
    std::cout << "Enforcing " << policy->getPolicyName() << " policy..." << std::endl;
    notifyObservers();
}

void Government::update(int newPopulation) {
    std::cout << "Updating population to " << newPopulation << std::endl;
    notifyObservers();
}

void Government::refundTaxes(double amount) {
    budget -= amount;
    std::cout << "Refunded taxes: " << amount << ". New budget: " << budget << std::endl;
}

void Government::registerObserver(GovObserver* observer) {
    observers.push_back(observer);
}

void Government::unregisterObserver(GovObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notifies all registered observers of changes
void Government::notifyObservers() {
    for (GovObserver* observer : observers) {
        observer->updateTaxRate(taxRate);
        observer->updatePolicy(Policy());
        observer->updateServices(CityService());
    }
}

void Government::addTaxesToBudget(double amount) {
    budget += amount;
    std::cout << "Added taxes to budget. New budget: " << budget << std::endl;
}
