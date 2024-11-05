/**
 * @file Citizen.cpp
 * @brief Implementation of the Citizen class.
 * 
 * This file contains the implementation of the Citizen class, which manages citizen attributes
 * and behaviors such as satisfaction, tax payments, job search, and relationship status.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city citizens and their properties.
 */

#include "Citizen.h"
#include <algorithm>
#include <iostream>
#include "BuildingManager.h"
#include "SatisfiedState.h"
#include "UnsatisfiedState.h"
#include "LeavingCityState.h"
#include "SatisfactionStrategy.h"
#include "Building.h"

/**
 * @brief Utility function to constrain a value within a specified range.
 * 
 * @tparam T The type of the value.
 * @param value The value to constrain.
 * @param min The minimum allowable value.
 * @param max The maximum allowable value.
 * @return T The constrained value.
 */
template <typename T>
T minMax(T value, T min, T max) {
    return std::max(min, std::min(value, max));
}

/**
 * @brief Constructs a new Citizen object.
 * 
 * @param name The name of the citizen.
 * @param age The age of the citizen.
 */
Citizen::Citizen(const std::string& name, int age) 
    : name(name), age(age), satisfaction(50.0f), currentState(nullptr), taxCooldown(false),
      lastTaxPayment(std::chrono::steady_clock::now() - taxCooldownPeriod) {}

/**
 * @brief Destroys the Citizen object.
 */
Citizen::~Citizen() {
    if (currentState != nullptr) {
        delete currentState;
        currentState = nullptr;
    }
}

/**
 * @brief Adds an observer to the citizen.
 * 
 * @param observer Pointer to the observer to be added.
 */
void Citizen::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

/**
 * @brief Removes an observer from the citizen.
 * 
 * @param observer Pointer to the observer to be removed.
 */
void Citizen::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 * @brief Detaches all observers from the citizen.
 */
void Citizen::detachAllObservers() {
    observers.clear();
}

/**
 * @brief Notifies all observers of changes to the citizen.
 */
void Citizen::notifyObservers() {
    for (auto* observer : observers) {
        observer->update(this);
    }
}

/**
 * @brief Gets the tax rate for the citizen.
 * 
 * @return float The tax rate.
 */
float Citizen::getTaxRate() const {
    return taxRate;
}

/**
 * @brief Sets the tax rate for the citizen.
 * 
 * @param rate The new tax rate.
 */
void Citizen::setTaxRate(float rate) {
    taxRate = rate;
}

/**
 * @brief Checks and updates the state of the citizen based on satisfaction.
 */
void Citizen::checkAndUpdateState() {
    if (satisfaction < 20.0f) {
        setState(new UnsatisfiedState());
    } else if (satisfaction >= 80.0f) {
        setState(new SatisfiedState());
    } else if (satisfaction == 0.0f) {
        setState(new LeavingCityState());
    }
}

/**
 * @brief Updates the satisfaction of the citizen based on all strategies.
 */
void Citizen::updateSatisfaction() {
    float totalSatisfaction = 0.0f;
    for (const auto& strategy : satisfactionStrategies) {
        totalSatisfaction += strategy->calculateSatisfaction(*this);
    }
    satisfaction = minMax(totalSatisfaction / satisfactionStrategies.size(), 0.0f, 100.0f);
}

/**
 * @brief Updates the satisfaction of the citizen by a specified adjustment.
 * 
 * @param adjustment The adjustment to the satisfaction.
 */
void Citizen::updateSatisfaction(float adjustment) {
    satisfaction = (satisfaction + adjustment > 100.0f) ? 100.0f : (satisfaction + adjustment < 0.0f) ? 0.0f : satisfaction + adjustment;
    std::cout << name << "'s updated satisfaction: " << satisfaction << std::endl;
}

/**
 * @brief Sets the state of the citizen.
 * 
 * @param newState Pointer to the new state.
 */
void Citizen::setState(CitizenState* newState) {
    if (currentState != nullptr) {
        delete currentState;
        currentState = nullptr;
    }
    currentState = newState;
}

/**
 * @brief Gets the age of the citizen.
 * 
 * @return int The age of the citizen.
 */
int Citizen::getAge() const { return age; }

/**
 * @brief Increments the age of the citizen by one year.
 */
void Citizen::incrementAge() { ++age; }

/**
 * @brief Adds a satisfaction strategy to the citizen.
 * 
 * @param strategy Shared pointer to the satisfaction strategy.
 */
void Citizen::addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy) {
    satisfactionStrategies.push_back(strategy);
}

/**
 * @brief Removes all satisfaction strategies from the citizen.
 */
void Citizen::removeSatisfactionStrategy() {
    satisfactionStrategies.clear();
}

/**
 * @brief Gets the relationship status of the citizen.
 * 
 * @return std::string The relationship status.
 */
std::string Citizen::getRelationshipStatus() const { return relationshipStatus; }

/**
 * @brief Sets the relationship status of the citizen.
 * 
 * @param status The new relationship status.
 */
void Citizen::setRelationshipStatus(const std::string& status) { relationshipStatus = status; }

/**
 * @brief Gets the duration of the citizen's marriage.
 * 
 * @return int The duration of the marriage in years.
 */
int Citizen::getMarriageDuration() const { return marriageDuration; }

/**
 * @brief Resets the duration of the citizen's marriage to zero.
 */
void Citizen::resetMarriageDuration() { marriageDuration = 0; }

/**
 * @brief Increments the duration of the citizen's marriage by one year.
 */
void Citizen::incrementMarriageDuration() { ++marriageDuration; }

/**
 * @brief Adds a child to the citizen's family.
 */
void Citizen::addChild() {
    std::cout << name << " has a new child.\n";
}

/**
 * @brief Deposits the monthly income of the citizen into their bank balance.
 */
void Citizen::depositMonthlyIncome() {
    if (income) {
        double monthlyIncome = income->calculateMonthlyIncome();
        bankBalance += monthlyIncome;
        std::cout << name << " received income: " << monthlyIncome << ". New bank balance: " << bankBalance << std::endl;
    }
}

/**
 * @brief Searches for and applies for a job for the citizen.
 * 
 * @param manager Reference to the BuildingManager.
 * @param building Pointer to the building where the job is located.
 * @param jobtitle The title of the job to apply for.
 */
void Citizen::searchAndApplyForJob(BuildingManager& manager, Building* building, std::string jobtitle) {
    bool foundjob = manager.assignJobToCitizen(jobtitle, this, building);

    if (foundjob) {
        this->jobTitle = jobtitle;
        notifyObservers();
        updateSatisfaction();
        std::cout << name << " found a job as " << jobtitle 
                  << " with monthly income: R" << income->calculateMonthlyIncome() << std::endl;
    } else {
        std::cout << name << " could not find a job as " << jobtitle << "." << std::endl;
    }
}

/**
 * @brief Gets the name of the citizen.
 * 
 * @return std::string The name of the citizen.
 */
std::string Citizen::getName() const { return name; }

/**
 * @brief Gets the satisfaction level of the citizen.
 * 
 * @return float The satisfaction level.
 */
float Citizen::getSatisfactionLevel() const { return satisfaction; }

/**
 * @brief Checks if the citizen is leaving the city.
 * 
 * @return true if the citizen is leaving.
 * @return false if the citizen is not leaving.
 */
bool Citizen::isLeaving() const { return satisfaction == 0; }

/**
 * @brief Sets the income of the citizen.
 * 
 * @param inc Shared pointer to the income.
 */
void Citizen::setIncome(std::shared_ptr<Income> inc) {
    income = inc;
}

/**
 * @brief Checks if the citizen is on cooldown for tax payments.
 * 
 * @return true if the citizen is on cooldown.
 * @return false if the citizen is not on cooldown.
 */
bool Citizen::isOnCooldown() const {
    if (!taxCooldown) {
        return false;
    }
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastTaxPayment);
    std::cout << "Elapsed time since last tax payment for " << name << ": " << elapsed.count() << " seconds\n";
    return elapsed < taxCooldownPeriod;
}

/**
 * @brief Processes the payment of taxes by the citizen.
 * 
 * @param taxType Pointer to the tax type.
 * @return double The amount of taxes paid.
 */
double Citizen::payTaxes(TaxType* taxType) {
    auto now = std::chrono::steady_clock::now();
    if (isOnCooldown()) {
        std::cout << "Citizen " << name << " is on cooldown. Taxes cannot be collected now.\n";
        return 0.0;
    }

    double tax = taxType->calculateTax(income.get()->calculateMonthlyIncome());
    tax = minMax(tax, 0.0, bankBalance);

    if (tax > 0.0) {
        bankBalance -= tax;
        taxCooldown = true;
        lastTaxPayment = now;
        std::cout << "Collected R" << tax << " in taxes from " << name << ".\n";
        return tax;
    } else {
        std::cout << "Citizen " << name << " has insufficient funds to pay taxes.\n";
        return 0.0;
    }
}

/**
 * @brief Sets the tax cooldown status for the citizen.
 * 
 * @param status The new tax cooldown status.
 */
void Citizen::setTaxCooldown(bool status) {
    taxCooldown = status;
}

/**
 * @brief Gets the tax cooldown status for the citizen.
 * 
 * @return true if the citizen is on cooldown.
 * @return false if the citizen is not on cooldown.
 */
bool Citizen::getTaxCooldown() const {
    return taxCooldown;
}

/**
 * @brief Gets the bank balance of the citizen.
 * 
 * @return double The bank balance.
 */
double Citizen::getBankBalance() const {
    return bankBalance;
}

/**
 * @brief Sets the bank balance of the citizen.
 * 
 * @param balance The new bank balance.
 */
void Citizen::setBankBalance(double balance) {
    bankBalance = balance;
}

/**
 * @brief Increases the bank balance of the citizen by a specified amount.
 * 
 * @param amount The amount to increase the bank balance by.
 */
void Citizen::incraseBankBalance(double amount) {
    bankBalance += amount;
}

/**
 * @brief Decreases the bank balance of the citizen by a specified amount.
 * 
 * @param amount The amount to decrease the bank balance by.
 */
void Citizen::subtractBankBalance(double amount) {
    bankBalance -= amount;
}