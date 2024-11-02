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
    double payTaxes(TaxType* taxType) override;
    double calculatePropertyTax();
    double calculateHouseholdIncome();
    void addResidents(std::shared_ptr<Citizen> citizen);
    void undoCollectTaxes();
    int getResidentialUnits() const;

private:
    int residentialUnits;
    float comfortLevel;
    std::string bType;
    std::vector<std::shared_ptr<Citizen>> residents;
    double propertyTax;
    double householdIncome;


protected:
	void calculateEconomicImpact();

	void calculateResourceConsumption();

	void calculateSatisfactionImpact();
};

#endif // RESIDENTIALBUILDING_H