// Citizen.h

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include <vector>
#include <chrono>
#include "CitizenObserver.h"
#include "Policy.h"
#include "CityService.h"
#include "CitizenState.h"
#include "SatisfactionStrategy.h"
#include "TaxType.h"

class Citizen {
public:
    // Constructor and Destructor
    Citizen(const std::string& name = "Unnamed Citizen", int age = 30,
            const std::string& relationshipStatus = "Single", const std::string& jobStatus = "Unemployed");
    virtual ~Citizen();

    // Prototype Pattern: Clone method
    virtual std::shared_ptr<Citizen> clone() const = 0;

    // Observer management
    void addObserver(std::shared_ptr<CitizenObserver> observer);
    void removeObserver(std::shared_ptr<CitizenObserver> observer);
    void notifyObservers();

    // State management
    void setState(std::shared_ptr<CitizenState> newState); // Change the citizen’s state
    void applyState();                     // Apply the current state's effect on satisfaction

    // Update Methods
    void updateJobSatisfaction();
    void updateMaritalStatus(bool status);
    void updateTaxRate(double rate);
    void updateHealth(bool status);
    void updateTaxRatePolicy(const Policy& policy);
    void updateResService(const CityService& service);
    void changeTaxRate(double rate);
    void updateEducationLevel(const std::string& level);
    void updateHealthStatus(bool status);
    void updateHousingSatisfaction(bool satisfaction);
    void updateBankBalance(double amount);
    void updateService(const CityService* service);
    void updatePolicy(const Policy* policy);
    bool isLeaving() const; 

    // Overloaded Satisfaction Update Methods
    void updateSatisfaction(float adjustment);  // Modify satisfaction by a certain amount
    void updateSatisfaction();                  // Overloaded method without parameters

    // Getters
    float getSatisfactionLevel() const;         // Retrieve the current satisfaction level
    int getAge() const;
    std::string getName() const;
    std::string getJob() const;
    bool getHealth() const;
    bool getMaritalStatus() const;
    std::string getResStatus() const;
    std::string getJobStatus() const;
    double getBankBalance() const;
    std::string getJobTitle() const;

    // Relationship management
    std::string getRelationshipStatus() const;
    void setRelationshipStatus(const std::string& status);
    void incrementMarriageDuration();
    void resetMarriageDuration();
    int getMarriageDuration() const;
    void addChild();
    int getNumChildren() const;

    // Satisfaction Strategies
    void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);
    void updateSatisfactionStrategies();

    // Job-related methods
    void setJobTitle(const std::string& title);
    void displayInfo() const;

    // Getters for strategy inputs
    bool isEmployed() const { return employed; }
    double getTaxRate() const { return taxRate; }
    float getHousingComfortLevel() const { return housingComfortLevel; }

    // Tax payment methods
    void setTaxRate(double rate);
    double calculateTax();
    double getIncome() const;
    void setIncome(double income);
    double payTaxes(std::shared_ptr<TaxType> taxType);
    bool canPayTax() const;
    void setTaxCooldown(bool status);
    bool getTaxCooldown() const;

protected:
    // Personal Information
    std::string name;
    int age;
    float satisfaction = 50.0f;
    std::string jobTitle = "Unemployed";
    std::string resStatus = "Resident";        // Residential status, default to "Resident"
    std::string relationshipStatus = "Single";
    int marriageDuration = 0;
    int numChildren = 0;
    bool maritalStatus = false;                // Indicates married status
    bool health = true;                        // Indicates health status (true for healthy)
    double bankBalance = 0.0;
    std::string educationLevel = "None";       // Default education level
    double income = 0.0;
    std::shared_ptr<CitizenState> currentState = nullptr;      // Current state pointer
    double taxRate = 0.1;                      // Default tax rate
    float housingComfortLevel = 5.0f;
    bool employed = false;
    bool housingSatisfaction = false;          // Indicates housing satisfaction status

    // Satisfaction Strategies
    std::vector<std::shared_ptr<SatisfactionStrategy>> satisfactionStrategies;

    // Cooldown Mechanism
    bool taxCooldown = false;
    std::chrono::steady_clock::time_point lastTaxPayment;
    const std::chrono::seconds taxCooldownPeriod = std::chrono::seconds(60); // Cooldown of 60 seconds

    // Observer Pattern Members
    std::vector<std::shared_ptr<CitizenObserver>> observers;   // List of observers
};

#endif // CITIZEN_H