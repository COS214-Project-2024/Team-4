/**
 * @file IndustrialBuildingBuilder.h
 * @brief Definition of the IndustrialBuildingBuilder class.
 * @version 1.0
 * 
 * This file contains the definition of the IndustrialBuildingBuilder class, which provides
 * methods to set attributes and build an IndustrialBuilding object.
 */

#ifndef INDUSTRIALBUILDINGBUILDER_H
#define INDUSTRIALBUILDINGBUILDER_H

#include "Builder.h"
#include "IndustrialBuilding.h"
#include <memory>
#include <string>

using namespace std;

/**
 * @class IndustrialBuildingBuilder
 * @brief Builder class for constructing IndustrialBuilding objects.
 * 
 * The IndustrialBuildingBuilder class provides methods to set attributes and build an IndustrialBuilding object.
 */
class IndustrialBuildingBuilder : public Builder {

private:
    float pollutionLevel = 0.0f;       ///< Pollution level of the industrial building
    float productionCapacity = 0.0f;   ///< Production capacity of the industrial building

public:
    /**
     * @brief Constructor for IndustrialBuildingBuilder.
     */
    IndustrialBuildingBuilder();

    /**
     * @brief Sets the pollution level of the building.
     * @param level The pollution level to set.
     * @return Reference to the current IndustrialBuildingBuilder object.
     */
    IndustrialBuildingBuilder& setPollutionLevel(float level);

    /**
     * @brief Sets the production capacity of the building.
     * @param capacity The production capacity to set.
     * @return Reference to the current IndustrialBuildingBuilder object.
     */
    IndustrialBuildingBuilder& setProductionCapacity(float capacity);

    /**
     * @brief Gets the pollution level of the building.
     * @return The pollution level of the building.
     */
    float getPollutionLevel();

    /**
     * @brief Gets the production capacity of the building.
     * @return The production capacity of the building.
     */
    float getProductionCapacity();

    /**
     * @brief Builds the industrial building and sets all the attributes of the building.
     * @return A unique pointer to the constructed IndustrialBuilding object.
     */
    std::unique_ptr<Building> build() override;
};

#endif // INDUSTRIALBUILDINGBUILDER_H