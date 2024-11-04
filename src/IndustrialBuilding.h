/**
 * @file IndustrialBuilding.h
 * @brief Definition of the IndustrialBuilding class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the IndustrialBuilding class, which represents an industrial building
 * with specific attributes and behaviors.
 */

#ifndef INDUSTRIALBUILDING_H
#define INDUSTRIALBUILDING_H

#include "Building.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * @class IndustrialBuilding
 * @brief Represents an industrial building with specific attributes and behaviors.
 * 
 * The IndustrialBuilding class inherits from the Building class and provides specific implementations
 * for an industrial building, including methods to calculate impacts, upgrade technology, and manage taxes.
 */
class IndustrialBuilding : public Building {

private:
    float pollutionLevel;       ///< Pollution level of the industrial building
    float productionCapacity;   ///< Production capacity of the industrial building
    string bType;               ///< Type of the building

public:
    /**
     * @brief Constructor for IndustrialBuilding.
     * @param name The name of the industrial building.
     * @param area The area of the industrial building.
     * @param floors The number of floors in the industrial building.
     * @param capacity The capacity of the industrial building.
     * @param citizenSatisfaction The citizen satisfaction level.
     * @param economicGrowth The economic growth contributed by the building.
     * @param resourceConsumption The resource consumption of the building.
     * @param pollutionLevel The pollution level of the building.
     * @param productionCapacity The production capacity of the building.
     */
    IndustrialBuilding(const std::string& name, float area, int floors, int capacity,
                        float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                        float pollutionLevel, float productionCapacity);

    /**
     * @brief Gets the type of the building.
     * @return The type of the building.
     */
    string getType() const override;

    /**
     * @brief Constructs the building.
     */
    void construct() override;

    /**
     * @brief Updates the impacts of the building by calculating economic impact, resource consumption, and satisfaction impact.
     */
    void updateImpacts() override;

    /**
     * @brief Upgrades the technology level of the building.
     * @param techLevel The new technology level to upgrade to.
     */
    void upgradeTech(float techLevel);

    /**
     * @brief Calculates and pays taxes for the building.
     * @param taxType The type of tax to calculate.
     * @return The amount of taxes paid.
     */
    double payTaxes(TaxType* taxType);

    /**
     * @brief Undoes the tax collection from the building.
     */
    void undoCollectTaxes();

protected:
    /**
     * @brief Calculates the economic impact of the building.
     */
    void calculateEconomicImpact();

    /**
     * @brief Calculates the resource consumption of the building.
     */
    void calculateResourceConsumption();

    /**
     * @brief Calculates the satisfaction impact of the building.
     */
    void calculateSatisfactionImpact();
};

#endif // INDUSTRIALBUILDING_H