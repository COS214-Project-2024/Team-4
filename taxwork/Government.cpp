#include "Government.h"
#include <iostream>
#include <algorithm>

using namespace std;

Government::Government(string name) : governmentName(name), taxRate(0.0), budget(0.0) {
    // Constructor implementation
}

void Government::setTax(double rate) {
    taxRate = rate;
    cout << "Tax rate set to " << taxRate << "%" << endl;
    notifyObservers();
}

double Government::getTaxRate() const {
    return taxRate;
}

void Government::notifyCitizen() {
    cout << "Notifying citizens..." << endl;
}

void Government::notifyBusinesses() {
    cout << "Notifying businesses..." << endl;
}

void Government::notifyServices() {
    cout << "Notifying services..." << endl;
}

void Government::allocateBudget(CityService& service, double amount) {
    budget -= amount;
  service.updateBudget(amount);
    cout << "Allocated " << amount << " to service. Remaining budget: " << budget << endl;
    notifyObservers();
}

void Government::revertBudgetAllocation(CityService& service, double amount) {
    budget += amount;
    service.updateBudget(-amount);
    cout << "Reverted allocation of " << amount << " from service. Remaining budget: " << budget << endl;
    notifyObservers();
}

void Government::enforcePolicy(Policy* policy) {
    cout << "Enforcing " << policy->getPolicyName() << " policy..." << endl;
    notifyObservers();
}

void Government::update(int newPopulation) {
    cout << "Updating population to " << newPopulation << endl;
    notifyObservers();
}

double Government::collectTaxes() {
    double collected = budget * taxRate / 100;
    budget += collected;
    cout << "Collected taxes: " << collected << ". New budget: " << budget << endl;
    return collected;
}

void Government::refundTaxes(double amount) {
    budget -= amount;
    cout << "Refunded taxes: " << amount << ". New budget: " << budget << endl;
}

void Government::registerObserver(GovObserver* observer) {
    observers.push_back(observer);
}

void Government::unregisterObserver(GovObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Government::notifyObservers() {
    for (GovObserver* observer : observers) {
        observer->updateTaxRate(taxRate);
        observer->updatePolicy(Policy());
        observer->updateServices(CityService());
    }
}