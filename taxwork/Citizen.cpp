// Citizen.cpp

#include "Citizen.h"
#include "CitizenObserver.h"
#include <algorithm>
#include <iostream>
#include "LeavingCityState.h"
#include "TaxType.h" // Ensure TaxType is included
#include <thread>    // For sleep (if needed in testing)
#include <chrono>

template <typename T>
T clamp(T value, T min, T max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

Citizen::Citizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle)
    : name(name),                 // Initializes 'name' (declared first)
      age(age),                   // Initializes 'age'
      satisfaction(50.0f),        // Initializes 'satisfaction'
      jobTitle(jobTitle),         // Initializes 'jobTitle'
      resStatus(resStatus),       // Initializes 'resStatus'
      relationshipStatus("Single"),
      marriageDuration(0),
      numChildren(0),
      maritalStatus(false),
      health(true),
      bankBalance(0.0),
      educationLevel("None"),
      income(0.0),
      currentState(nullptr),
      taxRate(0.1),
      housingComfortLevel(5.0f),
      employed(false),
      taxCooldown(false),
      lastTaxPayment(std::chrono::steady_clock::now() - taxCooldownPeriod)
{
    // Constructor body (if needed)
}

Citizen::~Citizen() {
    // No need to delete currentState as it is managed by shared_ptr
}

void Citizen::setState(std::shared_ptr<CitizenState> newState) {
    currentState = newState;
    notifyObservers();  // Notify observers of the state change
}

void Citizen::applyState() {
    if (currentState) {
        currentState->handleState(*this);
        notifyObservers();  // Notify observers after applying the state
    }
}

void Citizen::updateSatisfaction(float adjustment) {
    // Adjust satisfaction with clamping between 0 and 100
    satisfaction = ::clamp<float>(satisfaction + adjustment, 0.0f, 100.0f);
    notifyObservers();  // Notify observers that satisfaction has changed
}

float Citizen::getSatisfactionLevel() const {
    return satisfaction;
}

std::shared_ptr<Citizen> Citizen::clone() const {
    return nullptr; // Placeholder, each subclass should implement this.
}

// Observer management
void Citizen::addObserver(std::shared_ptr<CitizenObserver> observer) {
    observers.push_back(observer);
}

void Citizen::removeObserver(std::shared_ptr<CitizenObserver> observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Citizen::notifyObservers() {
    for (const auto& observer : observers) {
        observer->update(this);
    }
}

// Update methods
void Citizen::updateJobSatisfaction() {
    // Update job satisfaction logic here
    notifyObservers();
}

void Citizen::updateMaritalStatus(bool status) {
    maritalStatus = status;
    notifyObservers();
}

void Citizen::updateTaxRate(double rate) {
    (void)rate; // Suppress unused parameter warning
    // Apply the tax rate change to the citizen's financial state
    // Possibly adjust bank balance or satisfaction
    notifyObservers();
}

void Citizen::updateHealth(bool status) {
    health = status;
    notifyObservers();
}

void Citizen::updateTaxRatePolicy(const Policy& policy) {
    (void)policy; // Suppress unused parameter warning
    // Respond to tax policy change by adjusting tax-related satisfaction or bank balance
    notifyObservers();
}

void Citizen::updateResService(const CityService& service) {
    (void)service; // Suppress unused parameter warning
    // Adjust satisfaction or other attributes based on service provided
    notifyObservers();
}

void Citizen::changeTaxRate(double rate) {
    (void)rate; // Suppress unused parameter warning
    // Logic to directly change the tax rate
    notifyObservers();
}

void Citizen::updateEducationLevel(const std::string& level) {
    educationLevel = level;
    notifyObservers();
}

void Citizen::updateHealthStatus(bool status) {
    health = status;
    notifyObservers();
}

void Citizen::updateHousingSatisfaction(bool satisfaction) {
    housingSatisfaction = satisfaction;
    notifyObservers();
}

void Citizen::updateBankBalance(double amount) {
    bankBalance += amount;
    notifyObservers();
}

void Citizen::updateService(const CityService* service) {
    (void)service; // Suppress unused parameter warning
    // Logic to update citizen based on service provided
    notifyObservers();
}

void Citizen::updatePolicy(const Policy* policy) {
    (void)policy; // Suppress unused parameter warning
    // Logic to update citizen based on policy change
    notifyObservers();
}

// Getters
int Citizen::getAge() const {
    return age;
}

std::string Citizen::getName() const {
    return name;
}

std::string Citizen::getJob() const {
    return jobTitle;
}

bool Citizen::getHealth() const {
    return health;
}

bool Citizen::getMaritalStatus() const {
    return maritalStatus;
}

std::string Citizen::getResStatus() const {
    return resStatus;
}

std::string Citizen::getJobStatus() const {
    return jobTitle;
}

double Citizen::getBankBalance() const {
    return bankBalance;
}

// Relationship methods
std::string Citizen::getRelationshipStatus() const {
    return relationshipStatus;
}

void Citizen::setRelationshipStatus(const std::string& status) {
    relationshipStatus = status;
    notifyObservers();
}

void Citizen::incrementMarriageDuration() {
    if (relationshipStatus == "Married") {
        ++marriageDuration;
    }
}

void Citizen::resetMarriageDuration() {
    marriageDuration = 0;
}

int Citizen::getMarriageDuration() const {
    return marriageDuration;
}

void Citizen::addChild() {
    ++numChildren;
    notifyObservers();  // Notify observers of the new child
}

int Citizen::getNumChildren() const {
    return numChildren;
}

void Citizen::setJobTitle(const std::string& title) {
    jobTitle = title;
}

void Citizen::displayInfo() const {
    std::cout << "Name: " << name << ", Age: " << age
              << ", Job: " << jobTitle << std::endl;
}

bool Citizen::isLeaving() const {
    return dynamic_cast<LeavingCityState*>(currentState.get()) != nullptr;
}

void Citizen::addSatisfactionStrategy(std::shared_ptr<SatisfactionStrategy> strategy) {
    satisfactionStrategies.push_back(strategy);
}

void Citizen::updateSatisfaction() {
    float totalSatisfaction = 0.0;
    for (const auto& strategy : satisfactionStrategies) {
        totalSatisfaction += strategy->calculateSatisfaction(*this);
    }
    // Average satisfaction score if multiple strategies are used
    satisfaction = totalSatisfaction / satisfactionStrategies.size();
    std::cout << name << "'s updated satisfaction: " << satisfaction << std::endl;
}

// Tax-related methods
void Citizen::setTaxRate(double rate) {
    taxRate = rate;
}

double Citizen::calculateTax() {
    return income * taxRate;
}

void Citizen::setIncome(double income) {
    this->income = income;
}

double Citizen::payTaxes(std::shared_ptr<TaxType> taxType) {
    auto now = std::chrono::steady_clock::now();
    if (taxCooldown) {
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastTaxPayment);
        if (elapsed < taxCooldownPeriod) {
            std::cout << "Citizen " << name << " is on cooldown. Taxes cannot be collected now.\n";
            return 0.0;
        } else {
            taxCooldown = false; // Cooldown period has passed
        }
    }

    if (!taxCooldown) {
        double tax = taxType->calculateTax(income);
        tax = ::clamp(tax, 0.0, bankBalance); // Ensures tax is within [0, bankBalance]

        bankBalance -= tax;
        taxCooldown = true;
        lastTaxPayment = now; // Update the last tax payment time
        std::cout << "Collected $" << tax << " in taxes from " << name << ".\n";
        return tax;
    } else {
        return 0.0;
    }
}

double Citizen::getIncome() const {
    return income;
}

bool Citizen::canPayTax() const {
    return !taxCooldown && bankBalance > 0;
}

void Citizen::setTaxCooldown(bool status) {
    taxCooldown = status;
}

bool Citizen::getTaxCooldown() const {
    return taxCooldown;
}