/**
 * @file Business.h
 * @brief Header file for the Business class.
 * 
 * This file contains the declaration of the Business class, which manages business operations
 * such as updating tax rates, policies, and services, processing tax payments, and printing business details.
 * 
 * @version 0.1
 * @date 2024-11-04
 * 
 * @note This file is part of a project for managing city businesses and their properties.
 */

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
 * @class Business
 * @brief Represents a business that observes government policies and updates its state accordingly.
 * 
 * This class manages business operations such as updating tax rates, policies, and services,
 * processing tax payments, and printing business details.
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
     * @brief Constructs a new Business object.
     * 
     * @param initialRevenue The initial revenue of the business.
     * @param initialTaxRate The initial tax rate for the business.
     */
    Business(double initialRevenue, double initialTaxRate);

    /**
     * @brief Updates the tax rate for the business.
     * 
     * @param rate The new tax rate.
     */
    void updateTaxRate(double rate) override;

    /**
     * @brief Updates the business policy.
     * 
     * @param policy The new policy to be added.
     */
    void updatePolicy(Policy policy) override;

    /**
     * @brief Updates the services provided by the business.
     * 
     * @param service The new service to be added.
     */
    void updateServices(CityService service) override;

    /**
     * @brief Processes the payment of tax by the business.
     * 
     * @param amount The amount of tax to be paid.
     */
    void payTax(double amount);

    /**
     * @brief Adds a new service to the business.
     * 
     * @param serviceName The name of the service to be added.
     */
    void addService(const std::string& serviceName);

    /**
     * @brief Removes a service from the business.
     * 
     * @param serviceName The name of the service to be removed.
     */
    void removeService(const std::string& serviceName);

    /**
     * @brief Adds a new policy to the business.
     * 
     * @param policy The policy to be added.
     */
    void addPolicy(const Policy& policy);

    /**
     * @brief Removes a policy from the business.
     * 
     * @param policy The policy to be removed.
     */
    void removePolicy(const Policy& policy);

    /**
     * @brief Calculates the total tax to be paid based on the current tax rate and revenue.
     * 
     * @return double The total tax to be paid.
     */
    double calculateTax() const;

    /**
     * @brief Prints the details of the business.
     */
    void printDetails() const;

    /**
     * @brief Processes the payment of taxes by the business based on the tax type.
     * 
     * @param taxType Pointer to the tax type.
     * @return double The amount of taxes paid.
     */
    double payTaxes(TaxType* taxType);

    /**
     * @brief Sets the cooldown period for tax payments.
     * 
     * @param seconds The cooldown period in seconds.
     */
    void setTaxCooldownPeriod(int seconds);
};

#endif // BUSINESS_H