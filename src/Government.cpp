#include "Government.h"
#include <iostream>
#include <algorithm>

using namespace std;

// Constructor for Government
// Initializes the government with a name, tax rate, and budget
Government::Government(string name) : taxRate(0.0), budget(1500.0), governmentName(name) {
    // Constructor implementation
    cout << "Government created: " << governmentName << endl;
    taxSystem = new TaxSystem();
    taxSystem->addGovernment(this);
}
Government::~Government() {
    delete taxSystem;
}

// Sets the tax rate for the government
// Notifies observers of the tax rate change
void Government::setTax(double rate) {
    taxRate = rate;
    cout << "Tax rate set to " << taxRate << "%" << endl;
    notifyObservers();
}

// Gets the current tax rate
// Returns the tax rate
double Government::getTaxRate() const {
    return taxRate;
}

// Notifies citizens of changes
void Government::notifyCitizen() {
    cout << "Notifying citizens..." << endl;
}

// Notifies businesses of changes
void Government::notifyBusinesses() {
    cout << "Notifying businesses..." << endl;
}

// Notifies services of changes
void Government::notifyServices() {
    cout << "Notifying services..." << endl;
}

// Allocates budget to a city service
// Updates the budget and notifies observers
void Government::allocateBudget(CityService& service, double amount) {
    if (budget >= amount) {
        budget -= amount;
        service.updateBudget(amount);
        cout << "Allocated " << amount << " to service. Remaining budget: " << budget << endl;
        notifyObservers();
    } else {
        cout << "Insufficient budget to allocate " << amount << " to service." << endl;
    }
}

// Reverts the budget allocation to a city service
// Updates the budget and notifies observers
void Government::revertBudgetAllocation(CityService& service, double amount) {
    budget += amount;
    service.updateBudget(-amount);
    cout << "Reverted allocation of " << amount << " from service. Remaining budget: " << budget << endl;
    notifyObservers();
}

// Enforces a policy in the government
// Notifies observers of the policy enforcement
void Government::enforcePolicy(Policy policy) {
    cout << "Enforcing policy..." << endl;
    notifyObservers();
}

// Updates the population of the government
// Notifies observers of the population update
void Government::update(int newPopulation) {
    cout << "Updating population to " << newPopulation << endl;
    notifyObservers();
}

// Collects taxes based on the tax rate
// Updates the budget and returns the collected amount
double Government::collectTaxes() {
    double collected = budget * taxRate / 100;
    budget += collected;
    cout << "Collected taxes: " << collected << ". New budget: " << budget << endl;
    return collected;
}

// Refunds collected taxes
// Updates the budget
void Government::refundTaxes(double amount) {
    budget -= amount;
    cout << "Refunded taxes: " << amount << ". New budget: " << budget << endl;
}


// Registers an observer to the government
void Government::registerObserver(GovObserver* observer) {
    observers.push_back(observer);
}

// Unregisters an observer from the government
void Government::unregisterObserver(GovObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

// Notifies all registered observers of changes
void Government::notifyObservers() {
    for (GovObserver* observer : observers) {
        observer->updateTaxRate(taxRate);
        observer->updatePolicy(Policy());
        observer->updateServices(CityService("Default Service", 0.0)); // Provide default arguments
    }
}

// Gets the current budget
double Government::getBudget() const {
    return budget;
}

void Government::addTaxesToBudget(double amount) {
    budget += amount;
    cout << "Added taxes to budget. New budget: " << budget << endl;
}

TaxSystem* Government::getTaxSystem() {
    return taxSystem;
}
