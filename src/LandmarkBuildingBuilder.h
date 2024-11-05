/**
 * @file LandmarkBuildingBuilder.h
 * @brief Definition of the LandmarkBuildingBuilder class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the LandmarkBuildingBuilder class, which provides
 * methods to set attributes and build a LandmarkBuilding object.
 */

#ifndef LANDMARKBUILDINGBUILDER_H
#define LANDMARKBUILDINGBUILDER_H

#include "Builder.h"
#include "LandmarkBuilding.h"
#include <string>
#include <memory>

using namespace std;

/**
 * @class LandmarkBuildingBuilder
 * @brief Builder class for constructing LandmarkBuilding objects.
 * 
 * The LandmarkBuildingBuilder class provides methods to set attributes and build a LandmarkBuilding object.
 */
class LandmarkBuildingBuilder : public Builder {

private:
    int visitorCapacity = 0;       ///< Visitor capacity of the landmark building
    float culturalValue = 0.0f;    ///< Cultural value of the landmark building
    bool isHistoric = false;       ///< Indicates if the landmark building is historic

public:
    /**
     * @brief Constructor for LandmarkBuildingBuilder.
     */
    LandmarkBuildingBuilder();

    /**
     * @brief Gets the visitor capacity of the building.
     * @return The visitor capacity of the building.
     */
    int getVisitorCapacity();

    /**
     * @brief Sets the visitor capacity of the building.
     * @param visitorCapacity The visitor capacity to set.
     * @return Reference to the current LandmarkBuildingBuilder object.
     */
    LandmarkBuildingBuilder& setVisitorCapacity(int visitorCapacity);

    /**
     * @brief Gets the cultural value of the building.
     * @return The cultural value of the building.
     */
    float getCulturalValue();

    /**
     * @brief Sets the cultural value of the building.
     * @param culturalValue The cultural value to set.
     * @return Reference to the current LandmarkBuildingBuilder object.
     */
    LandmarkBuildingBuilder& setCulturalValue(float culturalValue);

    /**
     * @brief Gets whether the building is historic.
     * @return True if the building is historic, false otherwise.
     */
    bool getIsHistoric();

    /**
     * @brief Sets whether the building is historic.
     * @param isHistoric True if the building is historic, false otherwise.
     * @return Reference to the current LandmarkBuildingBuilder object.
     */
    LandmarkBuildingBuilder& setIsHistoric(bool isHistoric);

    /**
     * @brief Builds the landmark building and sets all the attributes of the building.
     * @return A unique pointer to the constructed LandmarkBuilding object.
     */
    std::unique_ptr<Building> build() override;
};

#endif // LANDMARKBUILDINGBUILDER_H