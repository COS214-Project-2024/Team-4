#ifndef SEWAGEMANAGEMENT_H
#define SEWAGEMANAGEMENT_H

/**
 * @file SewageManagement.h
 * @brief Declaration of the SewageManagement class.
 * 
 * This file contains the declaration of the SewageManagement class, which manages sewage services for buildings.
 * 
 * @version 1.0
 * @date 2024-11-04
 * 
 */

#include "Utility.h"

/**
 * @class SewageManagement
 * @brief A class to manage sewage services for buildings.
 * 
 * This class represents the sewage management service, which provides sewage services to buildings.
 */
class SewageManagement : public Utility {

public:
    /**
     * @brief Constructor for SewageManagement.
     * 
     * Initializes the sewage management service with the given utility mediator.
     * 
     * @param mediator Pointer to the UtilityMediator object.
     */
    SewageManagement(UtilityMediator* mediator);

    /**
     * @brief Registers a building with the sewage management service.
     * 
     * @param building Pointer to the Building object to be registered.
     */
    void registerBuilding(Building* building) override;

    /**
     * @brief Supplies sewage management services to a building.
     * 
     * Requests resources from the mediator and provides sewage management services if resources are available.
     * 
     * @param building Pointer to the Building object to receive services.
     */
    void supplyResources(Building* building) override;

    // /**
    //  * @brief Adjusts sewage management based on a citizen's requirements.
    //  * 
    //  * @param citizen Pointer to the Citizen object.
    //  */
    // void adjustForCitizen(Citizen* citizen) override;
};

#endif // SEWAGEMANAGEMENT_H