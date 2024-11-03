#ifndef BUSINESS_H
#define BUSINESS_H

#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"
#include <chrono>
#include <map>
#include <unordered_map>
#include <iostream>
#include "TaxType.h"
class Business : public GovObserver {

private:
    double revenue;
    double taxRate;
   std::unordered_map<char, std::chrono::steady_clock::time_point> lastTaxPayments; // Add this line
    std::chrono::seconds taxCooldownPeriod;


public:
  Business(double revenue, double taxRate);
  virtual ~Business(); // Add virtual destructor
    void updateTaxRate(double rate) override;
    void updatePolicy(Policy policy) override;
    void updateServices(CityService service) override;
    double payTaxes(TaxType* taxType);
    void setTaxCooldownPeriod(int seconds);
};

#endif