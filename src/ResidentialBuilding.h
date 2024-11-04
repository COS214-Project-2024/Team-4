/**
 * @file ResidentialBuilding.h
 * @brief Header file for the ResidentialBuilding class.
 * 
 * This file contains the definition of the ResidentialBuilding class, which 
 * represents a residential building in the simulation. It inherits from the 
 * Building class and includes additional attributes and methods specific to 
 * residential buildings.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef RESIDENTIALBUILDING_H
#define RESIDENTIALBUILDING_H

#include <string>
#include <vector>
#include <memory>
#include "Building.h"
#include "Citizen.h"
#include "TaxType.h"

/**
 * @class ResidentialBuilding
 * @brief Represents a residential building in the simulation.
 * 
 * The ResidentialBuilding class inherits from the Building class and includes 
 * additional attributes and methods specific to residential buildings, such as 
 * residential units, comfort level, and methods to manage residents and calculate 
 * taxes.
 */
class ResidentialBuilding : public Building {
public:
    /**
     * @brief Constructs a new ResidentialBuilding object.
     * 
     * @param name The name of the building.
     * @param area The area of the building.
     * @param floors The number of floors in the building.
     * @param capacity The capacity of the building.
     * @param citizenSatisfaction The satisfaction level of the citizens.
     * @param economicGrowth The economic growth associated with the building.
     * @param resourceConsumption The resource consumption of the building.
     * @param residentialUnits The number of residential units in the building.
     * @param comfortLevel The comfort level of the building.
     */
    ResidentialBuilding(const std::string& name, float area, int floors,
                        int capacity, float citizenSatisfaction,
                        float economicGrowth, float resourceConsumption,
                        int residentialUnits, float comfortLevel);

    /**
     * @brief Gets the type of the building.
     * 
     * @return The type of the building as a string.
     */
    std::string getType() const override;

    /**
     * @brief Updates the impacts of the building.
     */
    void updateImpacts() override;

    /**
     * @brief Upgrades the comfort level of the building.
     * 
     * @param comfort The new comfort level.
     */
    void upgradeComfort(float comfort);

    /**
     * @brief Constructs the building.
     */
    void construct() override;

    /**
     * @brief Pays taxes based on the given tax type.
     * 
     * @param taxType The type of tax to be paid.
     * @return The amount of taxes paid.
     */
    double payTaxes(TaxType* taxType);

    /**
     * @brief Calculates the property tax for the building.
     * 
     * @return The property tax amount.
     */
    double calculatePropertyTax();

    /**
     * @brief Adds a resident to the building.
     * 
     * @param citizen The citizen to be added.
     */
    void addResidents(Citizen* citizen);

    /**
     * @brief Undoes the collection of taxes.
     */
    void undoCollectTaxes();

    /**
     * @brief Gets the number of residential units in the building.
     * 
     * @return The number of residential units.
     */
    int getResidentialUnits() const;

private:
    int residentialUnits; ///< The number of residential units in the building.
    float comfortLevel; ///< The comfort level of the building.
    std::string bType; ///< The type of the building.
    double totalTaxCollected; ///< The total amount of taxes collected.
    double propertyTax; ///< The property tax amount.
    double totalPropertyTaxCollected; ///< The total amount of property taxes collected.
    double totalIncomeRaxCollected; ///< The total amount of income taxes collected.

protected:
    /**
     * @brief Calculates the economic impact of the building.
     */
    void calculateEconomicImpact() override;

    /**
     * @brief Calculates the resource consumption of the building.
     */
    void calculateResourceConsumption() override;

    /**
     * @brief Calculates the satisfaction impact of the building.
     */
    void calculateSatisfactionImpact() override; 

    std::vector<Citizen*> residents; ///< The list of residents in the building.
};

#endif // RESIDENTIALBUILDING_H