// Citizen.h

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include <vector>
#include "CitizenObserver.h"
#include "Policy.h"
#include "CityService.h"
#include "CitizenState.h"
#include "SatisfactionStrategy.h"

class Citizen {
protected:
std::string name;
    int age;
    std::string resStatus = "Resident";        // Residential status, default to "Resident"
    std::string jobStatus = "Unemployed";      // Employment status
    float satisfaction = 50.0f;
    std::string relationshipStatus = "Single";
    int marriageDuration = 0;
    int numChildren = 0;
    bool maritalStatus = false;                // Indicates married status
    bool health = true;                        // Indicates health status (true for healthy)
    double bankBalance = 0.0;
    std::string educationLevel = "None";       // Default education level
    bool housingSatisfaction = false;
    double income = 0.0;
    std::vector<CitizenObserver*> observers;   // List of observers
    CitizenState* currentState = nullptr;      // Current state pointer
    float taxRate = 0.1f;
    float housingComfortLevel = 5.0f;
    bool employed = false;
    std::vector<std::shared_ptr<SatisfactionStrategy>> satisfactionStrategies;


    

public:
    // Constructor and Destructor
    Citizen(const std::string& name = "Unnamed Citizen", int age = 30,
            const std::string& relationshipStatus = "Single", const std::string& jobStatus = "Unemployed");
    virtual ~Citizen();

    // Prototype Pattern: Clone method
    virtual std::shared_ptr<Citizen> clone() const = 0;

    // Observer management
    void addObserver(CitizenObserver* observer);
    void removeObserver(CitizenObserver* observer);
    void notifyObservers();

    void setState(CitizenState* newState); // Change the citizen’s state
    void applyState();                     // Apply the current state's effect on satisfaction

    // Update Methods
    void updateJobSatisfaction();
    void updateMaritalStatus(bool status);
    void updateTaxRate(double rate);
    void updateHealth(bool status);
    void updateSatisfaction(float newSatisfaction);
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
    void updateSatisfaction(float adjustment);  // Modify satisfaction by a certain amount
    float getSatisfactionLevel() const;         // Retrieve the current satisfaction level

    // Getters
    int getAge() const;
    std::string getName() const;
    std::string getJob() const;
    bool getHealth() const;
    bool getMaritalStatus() const;
    std::string getResStatus() const;
    std::string getJobStatus() const;
    double getBankBalance() const;

    // Relationship management
    std::string getRelationshipStatus() const;
    void setRelationshipStatus(const std::string& status);
    void incrementMarriageDuration();
    void resetMarriageDuration();
    int getMarriageDuration() const;
    void addChild();
    int getNumChildren() const;

    void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);
    void updateSatisfaction();

    // Getters for strategy inputs
    bool isEmployed() const { return employed; }
    float getTaxRate() const { return taxRate; }
    float getHousingComfortLevel() const { return housingComfortLevel; }
};

#endif // CITIZEN_H

