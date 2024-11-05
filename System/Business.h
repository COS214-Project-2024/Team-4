#ifndef BUSINESS_H
#define BUSINESS_H

#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <chrono>
#include "TaxType.h"

// Business class
// This class represents a business that observes government policies and updates its state accordingly
class Business : public GovObserver {

private:
    std::string name; // Name of the business
    double revenue;  // Revenue of the business
    double taxRate;  // Tax rate applied to the business
    std::vector<std::string> services; // List of services provided by the business
    std::vector<Policy> policies; // List of policies affecting the business
std::unordered_map<char, std::chrono::steady_clock::time_point> lastTaxPayments; // Add this line
    std::chrono::seconds taxCooldownPeriod;

public:
    // Constructor
    Business(double initialRevenue, double initialTaxRate,std::string name);

    // Updates the tax rate for the business
    void updateTaxRate(double rate) override;

    // Updates the business policy
    void updatePolicy(Policy policy) override;

    // Updates the services provided by the business
    void updateServices(CityService service) override;

    // Processes the payment of tax by the business
    void payTax(double amount);

    // Adds a new service to the business
    void addService(const std::string& serviceName);

    // Removes a service from the business
    void removeService(const std::string& serviceName);

    // Adds a new policy to the business
    void addPolicy(const Policy& policy);

    // Removes a policy from the business
    void removePolicy(const Policy& policy);

    // Calculates the total tax to be paid based on the current tax rate and revenue
    double calculateTax() const;

    // Prints the details of the business
    void printDetails() const;

    double payTaxes(TaxType* taxType);
    void setTaxCooldownPeriod(int seconds);

    double getRevenue();
    double getTaxRate();

    std::string getName();
};

#endif