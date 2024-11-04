/**
 * @file Government.cpp
 * @brief Implementation of the Government class.
 * @version 1.0
 * 
 * This file contains the implementation of the Government class, which manages various government-related
 * operations such as setting tax rates, allocating budgets, and notifying observers.
 */

#include "Government.h"
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * @brief Constructor for Government.
 * @param name The name of the government.
 */
Government::Government(string name) : taxRate(0.0), budget(1500.0), governmentName(name) {
    // Constructor implementation
}

/**
 * @brief Sets the tax rate for the government.
 * @param rate The new tax rate.
 */
void Government::setTax(double rate) {
    taxRate = rate;
    cout << "Tax rate set to " << taxRate << "%" << endl;
    notifyObservers();
}

/**
 * @brief Gets the current tax rate.
 * @return The current tax rate.
 */
double Government::getTaxRate() const {
    return taxRate;
}

/**
 * @brief Notifies citizens of changes.
 */
void Government::notifyCitizen() {
    cout << "Notifying citizens..." << endl;
}

/**
 * @brief Notifies businesses of changes.
 */
void Government::notifyBusinesses() {
    cout << "Notifying businesses..." << endl;
}

/**
 * @brief Notifies services of changes.
 */
void Government::notifyServices() {
    cout << "Notifying services..." << endl;
}

/**
 * @brief Allocates budget to a city service.
 * @param service The city service to allocate the budget to.
 * @param amount The amount to allocate.
 */
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

/**
 * @brief Reverts the budget allocation to a city service.
 * @param service The city service to revert the budget allocation from.
 * @param amount The amount to revert.
 */
void Government::revertBudgetAllocation(CityService& service, double amount) {
    budget += amount;
    service.updateBudget(-amount);
    cout << "Reverted allocation of " << amount << " from service. Remaining budget: " << budget << endl;
    notifyObservers();
}

/**
 * @brief Enforces a policy in the government.
 * @param policy The policy to enforce.
 */
void Government::enforcePolicy(Policy policy) {
    cout << "Enforcing policy..." << endl;
    notifyObservers();
}

/**
 * @brief Updates the population of the government.
 * @param newPopulation The new population value.
 */
void Government::update(int newPopulation) {
    cout << "Updating population to " << newPopulation << endl;
    notifyObservers();
}

/**
 * @brief Collects taxes based on the tax rate.
 * @return The amount of taxes collected.
 */
double Government::collectTaxes() {
    double collected = budget * taxRate / 100;
    budget += collected;
    cout << "Collected taxes: " << collected << ". New budget: " << budget << endl;
    return collected;
}

/**
 * @brief Refunds collected taxes.
 * @param amount The amount of taxes to refund.
 */
void Government::refundTaxes(double amount) {
    budget -= amount;
    cout << "Refunded taxes: " << amount << ". New budget: " << budget << endl;
}

/**
 * @brief Registers an observer to the government.
 * @param observer The observer to register.
 */
void Government::registerObserver(GovObserver* observer) {
    observers.push_back(observer);
}

/**
 * @brief Unregisters an observer from the government.
 * @param observer The observer to unregister.
 */
void Government::unregisterObserver(GovObserver* observer) {
    observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 * @brief Notifies all registered observers of changes.
 */
void Government::notifyObservers() {
    for (GovObserver* observer : observers) {
        observer->updateTaxRate(taxRate);
        observer->updatePolicy(Policy());
        observer->updateServices(CityService("Default Service", 0.0)); // Provide default arguments
    }
}

/**
 * @brief Gets the current budget.
 * @return The current budget.
 */
double Government::getBudget() const {
    return budget;
}

/**
 * @brief Adds taxes to the budget.
 * @param amount The amount of taxes to add.
 */
void Government::addTaxesToBudget(double amount) {
    budget += amount;
    cout << "Added taxes to budget. New budget: " << budget << endl;
}