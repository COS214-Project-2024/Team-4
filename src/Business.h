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

/**
 * @file Business.h
 * @brief Declaration of the Business class.
 * 
 * This file contains the declaration of the Business class, which represents a business
 * and includes methods to manage its revenue, tax rate, policies, and services.
 *
 * @version 1.0
 * @date 04/10/2024
 * 
 * @see Business.cpp
 */

/**
 * @class Business
 * @brief Represents a business that observes government policies and updates its state accordingly.
 * 
 * The Business class represents a business that observes government policies and updates its state accordingly.
 * It includes methods to manage its revenue, tax rate, policies, and services.
 * 
 * @version 1.0
 * @date 04/10/2024
 */
class Business : public GovObserver {

private:
    double revenue;  ///< Revenue of the business
    double taxRate;  ///< Tax rate applied to the business
    std::vector<std::string> services; ///< List of services provided by the business
    std::vector<Policy> policies; ///< List of policies affecting the business
    std::unordered_map<char, std::chrono::steady_clock::time_point> lastTaxPayments; ///< Last tax payments by type
    std::chrono::seconds taxCooldownPeriod; ///< Cooldown period for tax payments

public:
    /**
     * @brief Constructor for Business.
     * 
     * Initializes the business with initial revenue and tax rate.
     * 
     * @param initialRevenue The initial revenue of the business.
     * @param initialTaxRate The initial tax rate of the business.
     */
    Business(double initialRevenue, double initialTaxRate);

    /**
     * @brief Updates the tax rate for the business.
     * @param rate The new tax rate.
     */
    void updateTaxRate(double rate) override;

    /**
     * @brief Updates the business policy.
     * @param policy The new policy to be added.
     */
    void updatePolicy(Policy policy) override;

    /**
     * @brief Updates the services provided by the business.
     * @param service The new service to be added.
     */
    void updateServices(CityService service) override;

    /**
     * @brief Processes the payment of tax by the business.
     * @param amount The amount of tax to be paid.
     */
    void payTax(double amount);

    /**
     * @brief Adds a new service to the business.
     * @param serviceName The name of the service to be added.
     */
    void addService(const std::string& serviceName);

    /**
     * @brief Removes a service from the business.
     * @param serviceName The name of the service to be removed.
     */
    void removeService(const std::string& serviceName);

    /**
     * @brief Adds a new policy to the business.
     * @param policy The policy to be added.
     */
    void addPolicy(const Policy& policy);

    /**
     * @brief Removes a policy from the business.
     * @param policy The policy to be removed.
     */
    void removePolicy(const Policy& policy);

    /**
     * @brief Calculates the total tax to be paid based on the current tax rate and revenue.
     * @return The total tax to be paid.
     */
    double calculateTax() const;

    /**
     * @brief Prints the details of the business.
     */
    void printDetails() const;

    /**
     * @brief Processes the payment of taxes by the business.
     * @param taxType Pointer to the TaxType object.
     * @return The amount of tax paid.
     */
    double payTaxes(TaxType* taxType);

    /**
     * @brief Sets the tax cooldown period for the business.
     * @param seconds The cooldown period in seconds.
     */
    void setTaxCooldownPeriod(int seconds);

    /**
     * @brief Gets the revenue of the business.
     * @return The revenue of the business.
     */
    double getRevenue();

    /**
     * @brief Gets the tax rate of the business.
     * @return The tax rate of the business.
     */
    double getTaxRate();
};

#endif // BUSINESS_H