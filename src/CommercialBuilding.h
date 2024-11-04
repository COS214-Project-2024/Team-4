/**
 * @file CommercialBuilding.h
 * @brief Declaration of the CommercialBuilding class.
 *
 * This file contains the declaration of the CommercialBuilding class which manages commercial buildings.
 * @date 2024-11-04
 * @version 1.0
 */

#ifndef COMMERCIALBUILDING_H
#define COMMERCIALBUILDING_H

#include "Building.h"
#include "Business.h"
#include <memory>
#include <iostream>

using namespace std;

/**
 * @class CommercialBuilding
 * @brief Represents a commercial building.
 * 
 * The CommercialBuilding class inherits from the Building class and provides additional
 * functionality specific to commercial buildings, such as managing business units and customer traffic.
 */
class CommercialBuilding : public Building {
public:
    /**
     * @brief Constructor for CommercialBuilding.
     *
     * Initializes the commercial building with the given parameters.
     * 
     * @param name The name of the building.
     * @param area The area of the building.
     * @param floors The number of floors in the building.
     * @param capacity The capacity of the building.
     * @param citizenSatisfaction The citizen satisfaction level.
     * @param economicGrowth The economic growth impact.
     * @param resourceConsumption The resource consumption level.
     * @param businessUnits The number of business units in the building.
     * @param customerTraffic The customer traffic level.
     */
    CommercialBuilding(const std::string& name, float area, int floors, int capacity,
                       float citizenSatisfaction, float economicGrowth, float resourceConsumption,
                       int businessUnits, float customerTraffic);

    /**
     * @brief Destructor for CommercialBuilding.
     */
    ~CommercialBuilding(); // Destructor

    /**
     * @brief Gets the type of the building.
     * 
     * @return The type of the building.
     */
    std::string getType() const override;

    /**
     * @brief Updates the impacts of the building.
     *
     * Calculates the economic impact, resource consumption, and satisfaction impact.
     */
    void updateImpacts() override;

    /**
     * @brief Updates the customer traffic.
     * 
     * @param traffic The amount of traffic to add.
     */
    void updateCustomer(int traffic);

    /**
     * @brief Constructs the commercial building.
     */
    void construct() override;

    /**
     * @brief Pays taxes for the building.
     * 
     * @param taxType Pointer to the TaxType object.
     * @return The total amount of taxes collected.
     */
    double payTaxes(TaxType* taxType);

    /**
     * @brief Undoes the tax collection from the building.
     */
    void undoCollectTaxes();

    /**
     * @brief Sets the business in the building.
     * 
     * @param business Pointer to the Business object.
     */
    void setBusiness(Business* business);

private:
    int businessUnits; ///< Number of business units in the building.
    float customerTraffic; ///< Customer traffic level.
    Business* business; ///< Pointer to the Business object.
    std::string bType; ///< Type of the building.

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

#endif // COMMERCIALBUILDING_H