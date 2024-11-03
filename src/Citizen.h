// Citizen.h

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include <vector>
#include "CitizenObserver.h"
#include "Policy.h"
 #include "CitizenState.h"
 #include "SatisfactionStrategy.h"
 #include "Income.h"
#include "Jobs.h"
class BuildingManager;


class Citizen {
protected:
std::string name;
    int age;
    std::string resStatus = "Resident";        // Residential status, default to "Resident"
    //std::string jobStatus = "Unemployed";      // Employment status
    float satisfaction = 50.0f;
    std::string relationshipStatus = "Single";
    int marriageDuration = 0;
    int numChildren = 0;
    bool maritalStatus = false;                // Indicates married status
    bool health = true;                        // Indicates health status (true for healthy)
    double bankBalance = 0.0;
    std::string educationLevel = "None";       // Default education level
    bool housingSatisfaction = false;
    std::vector<CitizenObserver*> observers;   // List of observers
    CitizenState* currentState = nullptr;      // Current state pointer
    float taxRate = 0.1f;
  
    
    std::string jobTitle = "Unemployed";
    std::vector<std::shared_ptr<SatisfactionStrategy>> satisfactionStrategies;
    std::shared_ptr<Income> income;  // Citizen's income object (if employed)
    std::shared_ptr<Jobs> job;  // Job instance if citizen is employed


    

public:

float housingComfortLevel = 5.0f;
bool employed = false;
    // Constructor and Destructor
    Citizen(const std::string& name = "Unnamed Citizen", int age = 30,
            const std::string& relationshipStatus = "Single", const std::string& jobStatus = "Unemployed");
    virtual ~Citizen();

    void setName(const std::string& newName) { name = newName; }
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
    void updateTaxRatePolicy(const Policy& policy);
    
    void changeTaxRate(double rate);
    void updateEducationLevel(const std::string& level);
    void updateHealthStatus(bool status);
    void updateHousingSatisfaction(bool satisfaction);
    void updateBankBalance(double amount);
    
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
    
    std::string getJobTitle() const;

    void incrementAge() { age++; }  // Increment age by 1 year
    // Relationship management
    std::string getRelationshipStatus() const;
    void setRelationshipStatus(const std::string& status);
    void incrementMarriageDuration();
    void resetMarriageDuration();
    int getMarriageDuration() const;
    void addChild();
    int getNumChildren() const;

    //void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);
    void updateSatisfaction();

    //job stuff
    void setJobTitle(const std::string& title);
    void displayInfo() const;
    
    // Getters for strategy inputs
    
    float getTaxRate() const { return taxRate; }
    float getHousingComfortLevel() const { return housingComfortLevel; }
    void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);
    // Method to deposit monthly income into bank balance
    void depositMonthlyIncome();

    // Method for searching and applying for jobs
    bool searchAndApplyForJob(BuildingManager& manager);

    // Methods to handle monthly expenses
    void payChildAllowance();
    void payForGroceries(double groceryCost);

    // Getters for bank balance and employment status
    double getBankBalance() const ;
    bool isEmployed() const { return job != nullptr; }

    void setIncome(std::shared_ptr<Income> income);  // Sets the citizen's income

    // Tax payment methods
    void setTaxRate(double rate);
    double calculateTax();
    double getIncome() const;
    void setIncome(double income);
    double payTaxes(TaxType* taxType);
    bool canPayTax() const;
    void setTaxCooldown(bool status);
    bool getTaxCooldown() const;


// Cooldown Mechanism
bool taxCooldown;
std::chrono::steady_clock::time_point lastTaxPayment;
static constexpr std::chrono::seconds taxCooldownPeriod{60}; // Cooldown period of 60 seconds

};

#endif // CITIZEN_H

