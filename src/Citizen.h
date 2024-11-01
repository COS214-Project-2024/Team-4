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

class Citizen {
protected:
    std::string name;
    int age;
    std::string resStatus;       // Residential status
    std::string jobStatus;       // Employment status
    float satisfaction;
    bool maritalStatus;
    bool health;
    double bankBalance;
    std::string educationLevel;
    bool housingSatisfaction;
    double income;
    std::vector<CitizenObserver*> observers; // List of observers
    CitizenState* currentState;  // Current state
    

public:
    // Constructor and Destructor
    Citizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobStatus);
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
};

#endif // CITIZEN_H

