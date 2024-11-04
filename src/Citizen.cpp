// Citizen.cpp

#include "Citizen.h"
#include <algorithm>
#include <iostream>
#include "BuildingManager.h"
#include "SatisfiedState.h"
#include "UnsatisfiedState.h"
#include "LeavingCityState.h"
#include "SatisfactionStrategy.h"
#include "Building.h"

template <typename T>
T clamp(T value, T min, T max) {
    return std::max(min, std::min(value, max));
}

Citizen::Citizen(const std::string& name, int age) 
    : name(name), age(age), satisfaction(50.0f), currentState(nullptr), taxCooldown(false),
      lastTaxPayment(std::chrono::steady_clock::now() - taxCooldownPeriod) {}

Citizen::~Citizen() {
    if (currentState != nullptr) {
        delete currentState;
        currentState = nullptr;
    }
}

// Observer management
void Citizen::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

float Citizen::getTaxRate() const {
    return taxRate;
}

void Citizen::setTaxRate(float rate) {
    taxRate = rate;
}

void Citizen::checkAndUpdateState() {
    if (satisfaction < 20.0f) {
        setState(new UnsatisfiedState());
    } else if (satisfaction >= 80.0f) {
        setState(new SatisfiedState());
    } else if (satisfaction == 0.0f) {
        setState(new LeavingCityState());
    }
}

void Citizen::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Citizen::detachAllObservers(){
     observers.clear();
}

void Citizen::notifyObservers() {
    for (auto* observer : observers) {
        observer->update(this);
    }
}

// Update satisfaction based on all strategies
void Citizen::updateSatisfaction() {
    float totalSatisfaction = 0.0f;
    for (const auto& strategy : satisfactionStrategies) {
        totalSatisfaction += strategy->calculateSatisfaction(*this);
    }
    satisfaction = clamp(totalSatisfaction / satisfactionStrategies.size(), 0.0f, 100.0f);
}

void Citizen::updateSatisfaction(float adjustment) {
    satisfaction = (satisfaction + adjustment > 100.0f) ? 100.0f : (satisfaction + adjustment < 0.0f) ? 0.0f : satisfaction + adjustment;
    std::cout << name << "'s updated satisfaction: " << satisfaction << std::endl;
}

// State management
void Citizen::setState(CitizenState* newState) {
    // Delete the existing state to avoid memory leaks
    if (currentState != nullptr) {
        delete currentState;
        currentState = nullptr;
    }

    // Assign the new state
    currentState = newState;
}

// Age management
int Citizen::getAge() const { return age; }
void Citizen::incrementAge() { ++age; }

// Satisfaction Strategy management
void Citizen::addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy) {
    satisfactionStrategies.push_back(strategy);
}

void Citizen::removeSatisfactionStrategy() {
    satisfactionStrategies.clear();
}
// Relationship management
std::string Citizen::getRelationshipStatus() const { return relationshipStatus; }
void Citizen::setRelationshipStatus(const std::string& status) { relationshipStatus = status; }
int Citizen::getMarriageDuration() const { return marriageDuration; }
void Citizen::resetMarriageDuration() { marriageDuration = 0; }
void Citizen::incrementMarriageDuration() { ++marriageDuration; }
void Citizen::addChild() {
    // Placeholder for adding a child (could be linked to PopulationManager if needed)
    std::cout << name << " has a new child.\n";
}

// Monthly income deposit
void Citizen::depositMonthlyIncome() {
    if (income) {
        double monthlyIncome = income->calculateMonthlyIncome();
        bankBalance += monthlyIncome;
        std::cout << name << " received income: " << monthlyIncome << ". New bank balance: " << bankBalance << std::endl;
    }
}

// Search and apply for a job
void Citizen::searchAndApplyForJob(BuildingManager& manager, Building* building, std::string jobtitle) {
    bool foundjob = manager.assignJobToCitizen(jobtitle, this, building);

    if (foundjob) {
        // Set the job title to the newly assigned job
        this->jobTitle = jobtitle;

        // Notify observers about the job assignment
        notifyObservers();

        // Update satisfaction after getting a job
        updateSatisfaction();

        std::cout << name << " found a job as " << jobtitle 
                  << " with monthly income: R" << income->calculateMonthlyIncome() << std::endl;
    } else {
        std::cout << name << " could not find a job as " << jobtitle << "." << std::endl;
    }
}

// Getters
std::string Citizen::getName() const { return name; }
float Citizen::getSatisfactionLevel() const { return satisfaction; }
bool Citizen::isLeaving() const { return satisfaction == 0; }

// Setters
void Citizen::setIncome(std::shared_ptr<Income> inc) {
    income = inc;
}

// Citizen.cpp
bool Citizen::isOnCooldown() const {
    if (!taxCooldown) {
        return false;
    }
    auto now = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastTaxPayment);
    std::cout << "Elapsed time since last tax payment for " << name << ": " << elapsed.count() << " seconds\n";
    return elapsed < taxCooldownPeriod;
}

double Citizen::payTaxes(TaxType* taxType) {
    auto now = std::chrono::steady_clock::now();
    if (isOnCooldown()) {
        std::cout << "Citizen " << name << " is on cooldown. Taxes cannot be collected now.\n";
        return 0.0;
    }

    double tax = taxType->calculateTax(income.get()->calculateMonthlyIncome());
    tax = ::clamp(tax, 0.0, bankBalance);

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

// Tax-related methods
void Citizen::setTaxCooldown(bool status) {
    taxCooldown = status;
}

bool Citizen::getTaxCooldown() const {
    return taxCooldown;
}


