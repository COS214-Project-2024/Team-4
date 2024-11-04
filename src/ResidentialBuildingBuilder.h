/**
 * @file ResidentialBuildingBuilder.h
 * @brief Header file for the ResidentialBuildingBuilder class.
 * 
 * This file contains the definition of the ResidentialBuildingBuilder class, 
 * which is used to construct ResidentialBuilding objects with specific attributes.
 * 
 * @version 1.0
 * @date 2023-10-05
 */

#ifndef RESIDENTIALBUILDINGBUILDER_H
#define RESIDENTIALBUILDINGBUILDER_H

#include "Builder.h"
#include "ResidentialBuilding.h"
#include <string>
#include <memory>

using namespace std;

/**
 * @class ResidentialBuildingBuilder
 * @brief Builder class for constructing ResidentialBuilding objects.
 * 
 * The ResidentialBuildingBuilder class provides methods to set specific attributes 
 * for a ResidentialBuilding object and then construct the object.
 */
class ResidentialBuildingBuilder : public Builder {

private:
    int residentialUnit = 0; ///< The number of residential units.
    float comfort = 0.0f; ///< The comfort level of the building.

public:
    /**
     * @brief Constructs a new ResidentialBuildingBuilder object.
     */
    ResidentialBuildingBuilder();

    /**
     * @brief Sets the number of residential units in the building.
     * 
     * @param unit The number of residential units.
     * @return A reference to the ResidentialBuildingBuilder object.
     */
    ResidentialBuildingBuilder& setResidentialUnit(int unit);

    /**
     * @brief Sets the comfort level of the building.
     * 
     * @param comfort The comfort level.
     * @return A reference to the ResidentialBuildingBuilder object.
     */
    ResidentialBuildingBuilder& setComfort(float comfort);

    /**
     * @brief Gets the number of residential units in the building.
     * 
     * @return The number of residential units.
     */
    int getResidentialUnit();

    /**
     * @brief Gets the comfort level of the building.
     * 
     * @return The comfort level.
     */
    float getComfort();

    /**
     * @brief Builds the residential building and sets all the attributes of the building.
     * 
     * @return A unique pointer to the constructed ResidentialBuilding object.
     */
    std::unique_ptr<Building> build() override;
};

#endif // RESIDENTIALBUILDINGBUILDER_H