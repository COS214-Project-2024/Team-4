/**
 * @file Director.cpp
 * @brief Implementation of the Director class for constructing buildings.
 * 
 * This file contains the implementation of the Director class, which provides
 * methods to construct buildings of different sizes using a Builder object.
 * 
 * @version 1.0
 * @date 2023-10-01
 */

#include "Director.h"

/**
 * @brief Sets the builder object.
 * 
 * This method sets the builder object that will be used to construct buildings.
 * 
 * @param builder Reference to a Builder object.
 */
void Director::setBuilder(Builder& builder) {
    this->builder = &builder;
}

/**
 * @brief Constructs a small building.
 * 
 * This method constructs a small building with predefined parameters.
 * 
 * @return std::unique_ptr<Building> Pointer to the newly constructed small building.
 */
std::unique_ptr<Building> Director::constructSmallBuilding() {
    builder->setArea(500.0f)
           .setFloors(1)
           .setCapacity(50)
           .setCitizenSatisfaction(1.0f)
           .setEconomicGrowth(0.5f)
           .setResourceConsumption(0.3f);
    return builder->build();
}

/**
 * @brief Constructs a medium building.
 * 
 * This method constructs a medium building with predefined parameters.
 * 
 * @return std::unique_ptr<Building> Pointer to the newly constructed medium building.
 */
std::unique_ptr<Building> Director::constructMediumBuilding() {
    builder->setArea(1500.0f)
           .setFloors(3)
           .setCapacity(150)
           .setCitizenSatisfaction(2.0f)
           .setEconomicGrowth(1.5f)
           .setResourceConsumption(1.0f);
    return builder->build();
}

/**
 * @brief Constructs a large building.
 * 
 * This method constructs a large building with predefined parameters.
 * 
 * @return std::unique_ptr<Building> Pointer to the newly constructed large building.
 */
std::unique_ptr<Building> Director::constructLargeBuilding() {
    builder->setArea(3000.0f)
           .setFloors(5)
           .setCapacity(300)
           .setCitizenSatisfaction(3.0f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);
    return builder->build();
}