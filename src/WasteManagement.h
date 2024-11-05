/**
 * @file WasteManagement.h
 * @brief Declaration of the WasteManagement class.
 * 
 * This file contains the declaration of the WasteManagement class, which handles waste management services for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 * @note This file is part of a larger project that simulates the behavior of citizens and buildings in a city.
 */

#ifndef WASTEMANAGEMENT_H
#define WASTEMANAGEMENT_H

#include "Utility.h"

/**
 * @class WasteManagement
 * @brief A class that represents waste management services in the city.
 * 
 * The WasteManagement class is responsible for handling waste management services for buildings through a mediator.
 */
class WasteManagement : public Utility {

public:
    /**
     * @brief Constructor for the WasteManagement class.
     * 
     * @param mediator A pointer to the UtilityMediator for managing resources.
     */
    WasteManagement(UtilityMediator* mediator);

    /**
     * @brief Registers a building with the waste management service.
     * 
     * @param building A pointer to the building to be registered.
     */
    void registerBuilding(Building* building) override;

    /**
     * @brief Supplies waste management services to a building.
     * 
     * @param building A pointer to the building to receive waste management services.
     */
    void supplyResources(Building* building) override;

    /**
     * @brief Adjusts waste management services based on the new population size.
     * 
     * @param newPopulation The new population size.
     */
    void adjustForPopulation(int newPopulation) override;

    // /**
    //  * @brief Adjusts waste management services based on a citizen's requirements.
    //  * 
    //  * @param citizen A pointer to the citizen whose requirements are being considered.
    //  */
    // void adjustForCitizen(Citizen* citizen) override;
};

#endif // WASTEMANAGEMENT_H