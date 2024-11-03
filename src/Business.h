#ifndef BUSINESS_H
#define BUSINESS_H

#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"

// Business class
// This class represents a business that observes government policies and updates its state accordingly
class Business : public GovObserver {

private:
    double revenue;  // Revenue of the business
    double taxRate;  // Tax rate applied to the business

public:
    // Updates the tax rate for the business
    void updateTaxRate(double rate) override;

    // Updates the business policy
    void updatePolicy(Policy policy) override;

    // Updates the services provided by the business
    void updateServices(CityService service) override;

    // Processes the payment of tax by the business
    void payTax(double amount);
};

#endif