#ifndef BUSINESS_H
#define BUSINESS_H
//BUSINESS
#include "GovObserver.h"
#include "Policy.h"
#include "CityService.h"

class Business : public GovObserver {

private:
    double revenue;
    double taxRate;

public:
    void updateTaxRate(double rate) override;
    void updatePolicy(Policy policy) override;
    void updateServices(CityService service) override;
    void payTax(double amount);
};

#endif
