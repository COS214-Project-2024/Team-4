// Citizen.h

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
class Citizen {
private:
    float taxRate;
    std::string name;
    int age;
    float satisfaction = 50.0f;
    bool maritalStatus = false;
    bool health = true;
    double bankBalance = 0.0;
    std::string relationshipStatus = "Single";
    int marriageDuration = 0;
    CitizenState* currentState = nullptr;
    std::vector<CitizenObserver*> observers;
    std::vector<std::shared_ptr<SatisfactionStrategy>> satisfactionStrategies;
    std::shared_ptr<Income> income;
    std::shared_ptr<Jobs> job;
    std::string jobTitle = "Unemployed"; // Default job title
                   // Employment status

public:
    bool employed = false;
    Citizen(const std::string& name, int age);
    virtual ~Citizen();

    virtual std::shared_ptr<Citizen> clone() const = 0;
    // Observer pattern methods
    void addObserver(CitizenObserver* observer);
    void detachAllObservers();
    void removeObserver(CitizenObserver* observer);
    void notifyObservers();

    // State and satisfaction updates
    void setState(CitizenState* newState);
    void updateSatisfaction();

    // Relationship management
    std::string getRelationshipStatus() const;
    void setRelationshipStatus(const std::string& status);
    int getMarriageDuration() const;
    void resetMarriageDuration();
    void incrementMarriageDuration();
    void updateSatisfaction(float adjustment);
    void addChild();

    // Age management
    int getAge() const;
    void incrementAge();

    // Satisfaction Strategy
    void addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy);
    void removeSatisfactionStrategy();
    void setSatisfactionLevel(double level) { satisfaction = level; }
    
    // Basic citizen operations
    void depositMonthlyIncome();
    void searchAndApplyForJob(BuildingManager& manager , Building* building , std::string jobtitle);

    // Getters for name and satisfaction level
    std::string getName() const;
    float getSatisfactionLevel() const;
    bool isLeaving() const;
    void setIncome(std::shared_ptr<Income> income);

    void checkAndUpdateState();
    void setJobTitle(const std::string& jobTitle) { this->jobTitle = jobTitle; }
    std::string getJob() const { return jobTitle; }
    void setEmployed(bool status) { employed = status; }
    bool isEmployed() const { return employed; }
     float getTaxRate() const;  // Getter for tax rate
    void setTaxRate(float rate);  // Setter if tax rate needs to be adjusted
     double payTaxes(TaxType* taxType);

    //  bank balance 
    double getBankBalance() const;
    void setBankBalance(double balance);
    void incraseBankBalance(double amount);
    void subtractBankBalance(double amount);
//TAX STUFF
    void setTaxCooldown(bool status);
    bool getTaxCooldown() const;
    
 bool isOnCooldown() const; // Change access modifier to public
// Cooldown Mechanism
bool taxCooldown;
std::chrono::steady_clock::time_point lastTaxPayment;
static constexpr std::chrono::seconds taxCooldownPeriod{5}; // Cooldown period of 5 seconds


std::shared_ptr<Jobs> getjobobj(){return job;}
void setJob(std::shared_ptr<Jobs> job) { this->job = job; }
void unsetJob() { this->job = nullptr; }
};

#endif // CITIZEN_H