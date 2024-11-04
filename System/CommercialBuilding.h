#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include "Business.h"
#include <memory>
#include <iostream>

using namespace std;

class CommercialBuilding : public Building {
public:
    CommercialBuilding(const std::string& name, float area, int floors, int capacity,
                       float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                       int businessUnits, float customerTraffic);

    ~CommercialBuilding(); // Destructor

    std::string getType() const override;
    void updateImpacts() override;
    void updateCustomer(int traffic);
    void construct() override;
    double payTaxes(TaxType* taxType);
    void undoCollectTaxes();
    void setBusiness(std::shared_ptr<Business> business);
    void addCitizen(Citizen* citizen);
    void addBusiness(std::shared_ptr<Business> business);
    std::shared_ptr<Business> getBusiness() const;

private:
    int businessUnits;
    float customerTraffic;
    std::shared_ptr<Business> business;
    std::string bType;

protected:
    void calculateEconomicImpact();
    void calculateResourceConsumption();
    void calculateSatisfactionImpact();
};

#endif // COMMERCIALBUILDING_H