#include "Citizen.h"
#include "CitizenObserver.h"
Citizen::Citizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobStatus)
    : name(name), age(age), resStatus(resStatus), jobStatus(jobStatus),
      satisfaction(0.0), maritalStatus(false), health(true), bankBalance(0.0),
      educationLevel("None"), housingSatisfaction(false), income(0.0) {}

Citizen::~Citizen() {}

void Citizen::addObserver(CitizenObserver* observer) {
    observers.push_back(observer);
}

void Citizen::removeObserver(CitizenObserver* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Citizen::notifyObservers() {
    for (CitizenObserver* observer : observers) {
        observer->update(this);  // Notify each observer about the change
    }
}

void Citizen::updateJobSatisfaction() {
    // Logic to update job satisfaction
}

void Citizen::updateMaritalStatus() {
    // Logic to update marital status
}

void Citizen::updateEducationLevel() {
    // Logic to update education level
}

void Citizen::updateHealthStatus() {
    // Logic to update health status
}

void Citizen::updateHousingSatisfaction() {
    // Logic to update housing satisfaction
}

void Citizen::updateTaxRate(double taxRate) {
    // Logic to update tax rate
}

void Citizen::updateBankBalance(double amount) {
    // Logic to update bank balance
}

void Citizen::updateService(Service* service) {
    // Logic to update service
}

void Citizen::updatePolicy(const Policy* policy) {
    // Logic to update policy
}

std::string Citizen::getName() const {
    return name;
}

int Citizen::getAge() const {
    return age;
}

std::string Citizen::getJobStatus() const {
    return jobStatus;
}

std::string Citizen::getResStatus() const {
    return resStatus;
}
