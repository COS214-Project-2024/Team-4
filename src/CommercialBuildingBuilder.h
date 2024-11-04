/**
 * @file CommercialBuildingBuilder.h
 * @brief Declaration of the CommercialBuildingBuilder class.
 *
 * This file contains the declaration of the CommercialBuildingBuilder class which builds commercial buildings.
 * 
 * @version 1.0
 */

#ifndef COMMERCIALBUILDINGBUILDER_H
#define COMMERCIALBUILDINGBUILDER_H

#include "Builder.h"
#include "CommercialBuilding.h"
#include <string>
#include <memory>

using namespace std;

/**
 * @class CommercialBuildingBuilder
 * @brief Builder class for constructing CommercialBuilding objects.
 * 
 * The CommercialBuildingBuilder class provides methods to set various attributes of a commercial building
 * and build the final CommercialBuilding object.
 */
class CommercialBuildingBuilder : public Builder {

private:
    int businessUnits = 0; ///< Number of business units in the building.
    float customerTraffic = 0.0f; ///< Customer traffic level.

public:
    /**
     * @brief Sets the number of business units in the building.
     * 
     * @param units The number of business units.
     * @return Reference to the current builder object.
     */
    CommercialBuildingBuilder& setBusinessUnits(int units);

    /**
     * @brief Gets the number of business units in the building.
     * 
     * @return The number of business units.
     */
    int getBusinessUnits();

    /**
     * @brief Gets the customer traffic in the building.
     * 
     * @return The customer traffic.
     */
    float getCustomerTraffic();

    /**
     * @brief Sets the customer traffic in the building.
     * 
     * @param customerTraffic The customer traffic.
     * @return Reference to the current builder object.
     */
    CommercialBuildingBuilder& setCustomerTraffic(float customerTraffic);

    /**
     * @brief Default constructor for CommercialBuildingBuilder.
     */
    CommercialBuildingBuilder();

    /**
     * @brief Builds the commercial building and sets all the attributes of the building.
     * 
     * @return A unique pointer to the built CommercialBuilding object.
     */
    std::unique_ptr<Building> build() override;
};

#endif // COMMERCIALBUILDINGBUILDER_H