// ResidentialBuilding.h

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include <string>
#include <vector>
#include <memory>
#include "Building.h"
#include "Citizen.h"
#include "TaxType.h"

class ResidentialBuilding : public Building {
public:
    ResidentialBuilding(const std::string& name, float area, int floors,
                        int capacity, float citizenSatisfaction,
                        float economicGrowth, float resourceConsumption,
                        int residentialUnits, float comfortLevel);

    std::string getType() const override;
    void updateImpacts() override;
    void upgradeComfort(float comfort);
    void construct() override;
    double payTaxes(TaxType* taxType);
    double calculatePropertyTax();
    void addResidents(Citizen* citizen);
    void undoCollectTaxes();
    int getResidentialUnits() const;
    void addCitizen(Citizen* citizen) override;  // Override the base class method
    void addBusiness(Business* business); // do nothing

private:
    int residentialUnits;
    float comfortLevel;
    std::string bType;
    double totalTaxCollected;
    double propertyTax;
    double totalPropertyTaxCollected;
    double totalIncomeRaxCollected;
    std::vector<Citizen*> residents; 

protected:
    void calculateEconomicImpact() override;
    void calculateResourceConsumption() override;
    void calculateSatisfactionImpact() override; 
      

};

#endif // RESIDENTIALBUILDING_H