/**
 * @file PowerPlant.h
 * @brief Definition of the PowerPlant class.
 * @version 1.0
 * 
 * This file contains the definition of the PowerPlant class, which represents a power plant
 * that supplies power to buildings through a mediator.
 */

#ifndef __POWERPLANT_H
#define __POWERPLANT_H

#include "Utility.h"
#include "UtilityMediator.h"
#include "ResourceType.h"

class UtilityMediator;

/**
 * @class PowerPlant
 * @brief Represents a power plant that supplies power to buildings.
 * 
 * The PowerPlant class inherits from the Utility class and provides methods to register buildings,
 * supply resources, and generate electricity.
 */
class PowerPlant : public Utility {
    private:
        UtilityMediator* mediator; ///< Pointer to the UtilityMediator.

    public:
        /**
         * @brief Constructor for PowerPlant.
         * @param mediator Pointer to the UtilityMediator.
         */
        PowerPlant(UtilityMediator* mediator);

        /**
         * @brief Registers a building to receive power.
         * @param building Pointer to the building to be registered.
         */
        void registerBuilding(Building* building) override;

        /**
         * @brief Supplies power to a building.
         * @param building Pointer to the building to receive power.
         */
        void supplyResources(Building* building) override;

        //void generateElectricity(Building *building);

        //void adjustForCitizen(Citizen* citizen) override;
        //PowerPlant();
};

#endif // __POWERPLANT_H