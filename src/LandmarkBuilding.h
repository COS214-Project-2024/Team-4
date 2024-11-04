/**
 * @file LandmarkBuilding.h
 * @brief Definition of the LandmarkBuilding class.
 * @version 1.0
 * 
 * This file contains the definition of the LandmarkBuilding class, which represents a landmark building
 * with specific attributes and behaviors.
 */

#ifndef LANDMARKBUILDING_H
#define LANDMARKBUILDING_H

#include "Building.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * @class LandmarkBuilding
 * @brief Represents a landmark building with specific attributes and behaviors.
 * 
 * The LandmarkBuilding class inherits from the Building class and provides specific implementations
 * for a landmark building, including methods to calculate impacts, host events, and manage taxes.
 */
class LandmarkBuilding : public Building {

private:
    int visitorCapacity;       ///< Visitor capacity of the landmark building
    float culturalValue;       ///< Cultural value of the landmark building
    bool isHistoric;           ///< Indicates if the landmark building is historic
    string bType;              ///< Type of the building

public:
    /**
     * @brief Constructor for LandmarkBuilding.
     * @param name The name of the landmark building.
     * @param area The area of the landmark building.
     * @param floors The number of floors in the landmark building.
     * @param capacity The capacity of the landmark building.
     * @param citizenSatisfactionImpact The citizen satisfaction level.
     * @param economicGrowthImpact The economic growth contributed by the building.
     * @param resourceConsumption The resource consumption of the building.
     * @param visitorCapacity The visitor capacity of the landmark building.
     * @param culturalValue The cultural value of the landmark building.
     * @param isHistoric Indicates if the landmark building is historic.
     */
    LandmarkBuilding(const std::string& name, float area, int floors, int capacity,
                     float citizenSatisfactionImpact, float economicGrowthImpact,
                     float resourceConsumption, int visitorCapacity, float culturalValue, bool isHistoric);

    /**
     * @brief Gets the type of the building.
     * @return The type of the building.
     */
    string getType() const override;

    /**
     * @brief Updates the impacts of the building by calculating economic impact, resource consumption, and satisfaction impact.
     */
    void updateImpacts() override;

    /**
     * @brief Constructs the building.
     */
    void construct() override;

    /**
     * @brief Hosts an event in the building.
     * @param visitors The number of visitors attending the event.
     */
    void hostEvent(int visitors);

    /**
     * @brief Pays taxes for the building.
     * @param taxType The type of tax to calculate.
     * @return The amount of taxes paid.
     */
    double payTaxes(TaxType* taxType) override;

    /**
     * @brief Undoes the tax collection from the building.
     */
    void undoCollectTaxes() override;

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

#endif // LANDMARKBUILDING_H