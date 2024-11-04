/**
 * @file Citizen.h
 * @brief Header file for the Citizen class.
 * 
 * This file contains the declaration of the Citizen class, which manages citizen attributes
 * and behaviors such as satisfaction, tax payments, job search, and relationship status.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city citizens and their properties.
 */

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include <vector>
#include "CitizenObserver.h"
#include "CitizenState.h"
#include "Income.h"
#include "Jobs.h"
#include "TaxType.h"
#include <chrono>

class BuildingManager;
class SatisfactionStrategy;
class Building;

/**
 * @class Citizen
 * @brief Manages citizen attributes and behaviors.
 * 
 * This class manages citizen attributes and behaviors such as satisfaction, tax payments, job search, and relationship status.
 */
class Citizen {
private:
    float taxRate; ///< Tax rate for the citizen
    std::string name; ///< Name of the citizen
    int age; ///< Age of the citizen
    float satisfaction = 50.0f; ///< Satisfaction level of the citizen
    bool maritalStatus = false; ///< Marital status of the citizen
    bool health = true; ///< Health status of the citizen
    double bankBalance = 0.0; ///< Bank balance of the citizen
    std::string relationshipStatus = "Single"; ///< Relationship status of the citizen
    int marriageDuration = 0; ///< Duration of the citizen's marriage
    CitizenState* currentState = nullptr; ///< Current state of the citizen
    std::vector<CitizenObserver*> observers; ///< List of observers for the citizen
    std::vector<std::shared_ptr<SatisfactionStrategy>> satisfactionStrategies; ///< List of satisfaction strategies for the citizen
    std::shared_ptr<Income> income; ///< Income of the citizen
    std::shared_ptr<Jobs> job; ///< Job of the citizen
    std::string jobTitle = "Unemployed"; ///< Job title of the citizen
    bool taxCooldown; ///< Tax cooldown status
    std::chrono::steady_clock::time_point lastTaxPayment; ///< Last tax payment time
    static constexpr std::chrono::seconds taxCooldownPeriod{5}; ///< Cooldown period for tax payments

public:
    bool employed = false; ///< Employment status of the citizen

    /**
     * @brief Constructs a new Citizen object.
     * 
     * @param name The name of the citizen.
     * @param age The age of the citizen.
     */
    Citizen(const std::string& name, int age);

    /**
     * @brief Destroys the Citizen object.
     */
    virtual ~Citizen();

    /**
     * @brief Clones the citizen object.
     * 
     * @return std::shared_ptr<Citizen> A shared pointer to the cloned citizen.
     */
    virtual std::shared_ptr<Citizen> clone() const = 0;

    // Observer pattern methods
    /**
     * @brief Adds an observer to the citizen.
     * 
     * @param observer Pointer to the observer to be added.
     */
    void addObserver(CitizenObserver* observer);

    /**
     * @brief Detaches all observers from the citizen.
     */
    void detachAllObservers();

    /**
     * @brief Removes an observer from the citizen.
     * 
     * @param observer Pointer to the observer to be removed.
     */
    void removeObserver(CitizenObserver* observer);

    /**
     * @brief Notifies all observers of changes to the citizen.
     */
    void notifyObservers();

    // State and satisfaction updates
    /**
     * @brief Sets the state of the citizen.
     * 
     * @param newState Pointer to the new state.
     */
    void setState(CitizenState* newState);

    /**
     * @brief Updates the satisfaction of the citizen based on all strategies.
     */
    void updateSatisfaction();

    // Relationship management
    /**
     * @brief Gets the relationship status of the citizen.
     * 
     * @return std::string The relationship status.
     */
    std::string getRelationshipStatus() const;

    /**
     * @brief Sets the relationship status of the citizen.
     * 
     * @param status The new relationship status.
     */
    void setRelationshipStatus(const std::string& status);

    /**
     * @brief Gets the duration of the citizen's marriage.
     * 
     * @return int The duration of the marriage in years.
     */
    int getMarriageDuration() const;

    /**
     * @brief Resets the duration of the citizen's marriage to zero.
     */
    void resetMarriageDuration();

    /**
     * @brief Increments the duration of the citizen's marriage by one year.
     */
    void incrementMarriageDuration();

    /**
     * @brief Updates the satisfaction of the citizen by a specified adjustment.
     * 
     * @param adjustment The adjustment to the satisfaction.
     */
    void updateSatisfaction(float adjustment);

    /**
     * @brief Adds a child to the citizen's family.
     */
    void addChild();

    // Age management
    /**
     * @brief Gets the age of the citizen.
     * 
     * @return int The age of the citizen.
     */
    int getAge() const;

    /**
     * @brief Increments the age of the citizen by one year.
     */
    void incrementAge();

    // Satisfaction Strategy
    /**
     * @brief Adds a satisfaction strategy to the citizen.
     * 
     * @param strategy Shared pointer to the satisfaction strategy.
     */
    void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);

    /**
     * @brief Removes all satisfaction strategies from the citizen.
     */
    void removeSatisfactionStrategy();

    /**
     * @brief Sets the satisfaction level of the citizen.
     * 
     * @param level The new satisfaction level.
     */
    void setSatisfactionLevel(double level) { satisfaction = level; }

    // Basic citizen operations
    /**
     * @brief Deposits the monthly income of the citizen into their bank balance.
     */
    void depositMonthlyIncome();

    /**
     * @brief Searches for and applies for a job for the citizen.
     * 
     * @param manager Reference to the BuildingManager.
     * @param building Pointer to the building where the job is located.
     * @param jobtitle The title of the job to apply for.
     */
    void searchAndApplyForJob(BuildingManager& manager, Building* building, std::string jobtitle);

    // Getters for name and satisfaction level
    /**
     * @brief Gets the name of the citizen.
     * 
     * @return std::string The name of the citizen.
     */
    std::string getName() const;

    /**
     * @brief Gets the satisfaction level of the citizen.
     * 
     * @return float The satisfaction level.
     */
    float getSatisfactionLevel() const;

    /**
     * @brief Checks if the citizen is leaving the city.
     * 
     * @return true if the citizen is leaving.
     * @return false if the citizen is not leaving.
     */
    bool isLeaving() const;

    /**
     * @brief Sets the income of the citizen.
     * 
     * @param income Shared pointer to the income.
     */
    void setIncome(std::shared_ptr<Income> income);

    /**
     * @brief Checks and updates the state of the citizen based on satisfaction.
     */
    void checkAndUpdateState();

    /**
     * @brief Sets the job title of the citizen.
     * 
     * @param jobTitle The new job title.
     */
    void setJobTitle(const std::string& jobTitle) { this->jobTitle = jobTitle; }

    /**
     * @brief Gets the job title of the citizen.
     * 
     * @return std::string The job title.
     */
    std::string getJob() const { return jobTitle; }

    /**
     * @brief Sets the employment status of the citizen.
     * 
     * @param status The new employment status.
     */
    void setEmployed(bool status) { employed = status; }

    /**
     * @brief Checks if the citizen is employed.
     * 
     * @return true if the citizen is employed.
     * @return false if the citizen is not employed.
     */
    bool isEmployed() const { return employed; }

    /**
     * @brief Gets the tax rate for the citizen.
     * 
     * @return float The tax rate.
     */
    float getTaxRate() const;

    /**
     * @brief Sets the tax rate for the citizen.
     * 
     * @param rate The new tax rate.
     */
    void setTaxRate(float rate);

    /**
     * @brief Processes the payment of taxes by the citizen.
     * 
     * @param taxType Pointer to the tax type.
     * @return double The amount of taxes paid.
     */
    double payTaxes(TaxType* taxType);

    // Bank balance management
    /**
     * @brief Gets the bank balance of the citizen.
     * 
     * @return double The bank balance.
     */
    double getBankBalance() const;

    /**
     * @brief Sets the bank balance of the citizen.
     * 
     * @param balance The new bank balance.
     */
    void setBankBalance(double balance);

    /**
     * @brief Increases the bank balance of the citizen by a specified amount.
     * 
     * @param amount The amount to increase the bank balance by.
     */
    void incraseBankBalance(double amount);

    /**
     * @brief Decreases the bank balance of the citizen by a specified amount.
     * 
     * @param amount The amount to decrease the bank balance by.
     */
    void subtractBankBalance(double amount);

    // Tax cooldown management
    /**
     * @brief Sets the tax cooldown status for the citizen.
     * 
     * @param status The new tax cooldown status.
     */
    void setTaxCooldown(bool status);

    /**
     * @brief Gets the tax cooldown status for the citizen.
     * 
     * @return true if the citizen is on cooldown.
     * @return false if the citizen is not on cooldown.
     */
    bool getTaxCooldown() const;

    /**
     * @brief Checks if the citizen is on cooldown for tax payments.
     * 
     * @return true if the citizen is on cooldown.
     * @return false if the citizen is not on cooldown.
     */
    bool isOnCooldown() const;

    /**
     * @brief Gets the job object of the citizen.
     * 
     * @return std::shared_ptr<Jobs> The job object.
     */
    std::shared_ptr<Jobs> getjobobj() { return job; }

    /**
     * @brief Sets the job object of the citizen.
     * 
     * @param job Shared pointer to the job.
     */
    void setJob(std::shared_ptr<Jobs> job) { this->job = job; }

    /**
     * @brief Unsets the job object of the citizen.
     */
    void unsetJob() { this->job = nullptr; }
};

#endif // CITIZEN_H