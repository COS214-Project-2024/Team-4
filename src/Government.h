/**
 * @file Government.h
 * @brief Definition of the Government class.
 * @version 1.0
 * 
 * This file contains the definition of the Government class, which manages various government-related
 * operations such as setting tax rates, allocating budgets, and notifying observers.
 */

#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include "GovObserver.h"
#include "CityService.h"
#include "Policy.h"
#include <vector>
#include <string>

/**
 * @class Government
 * @brief Manages various government-related operations.
 * 
 * The Government class manages various government-related operations such as setting tax rates,
 * allocating budgets, and notifying observers.
 */
class Government {

private:
    double taxRate;                      ///< Tax rate applied by the government
    double budget;                       ///< Budget of the government
    std::string governmentName;          ///< Name of the government
    std::vector<GovObserver*> observers; ///< List of observers

public:
    /**
     * @brief Constructor for Government.
     * @param name The name of the government.
     */
    Government(std::string name);

    /**
     * @brief Sets the tax rate for the government.
     * @param rate The new tax rate.
     */
    void setTax(double rate);

    /**
     * @brief Gets the current tax rate.
     * @return The current tax rate.
     */
    double getTaxRate() const;

    /**
     * @brief Notifies citizens of changes.
     */
    void notifyCitizen();

    /**
     * @brief Notifies businesses of changes.
     */
    void notifyBusinesses();

    /**
     * @brief Notifies services of changes.
     */
    void notifyServices();

    /**
     * @brief Allocates budget to a city service.
     * @param service The city service to allocate the budget to.
     * @param amount The amount to allocate.
     */
    void allocateBudget(CityService& service, double amount);

    /**
     * @brief Reverts the budget allocation to a city service.
     * @param service The city service to revert the budget allocation from.
     * @param amount The amount to revert.
     */
    void revertBudgetAllocation(CityService& service, double amount);

    /**
     * @brief Enforces a policy in the government.
     * @param policy The policy to enforce.
     */
    void enforcePolicy(Policy policy);

    /**
     * @brief Updates the population of the government.
     * @param newPopulation The new population value.
     */
    void update(int newPopulation);

    /**
     * @brief Collects taxes based on the tax rate.
     * @return The amount of taxes collected.
     */
    double collectTaxes();

    /**
     * @brief Refunds collected taxes.
     * @param amount The amount of taxes to refund.
     */
    void refundTaxes(double amount);

    /**
     * @brief Adds taxes to the budget.
     * @param amount The amount of taxes to add.
     */
    void addTaxesToBudget(double amount);

    /**
     * @brief Registers an observer to the government.
     * @param observer The observer to register.
     */
    void registerObserver(GovObserver* observer);

    /**
     * @brief Unregisters an observer from the government.
     * @param observer The observer to unregister.
     */
    void unregisterObserver(GovObserver* observer);

    /**
     * @brief Notifies all registered observers of changes.
     */
    void notifyObservers();

    /**
     * @brief Gets the current budget.
     * @return The current budget.
     */
    double getBudget() const;
};

#endif // GOVERNMENT_H