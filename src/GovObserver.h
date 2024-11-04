/**
 * @file GovObserver.h
 * @brief Definition of the GovObserver class.
 * @version 1.0
 * 
 * This file contains the definition of the GovObserver class, which provides methods to update
 * the tax rate, policy, and services for the observer.
 */

#ifndef GOVOBSERVER_H
#define GOVOBSERVER_H

class Policy; // Forward declaration
class CityService; // Forward declaration

/**
 * @class GovObserver
 * @brief Abstract base class for observers that monitor government changes.
 * 
 * This class provides methods to update the tax rate, policy, and services for the observer.
 */
class GovObserver {
public:
    /**
     * @brief Updates the tax rate for the observer.
     * @param rate The new tax rate.
     */
    virtual void updateTaxRate(double rate) = 0;

    /**
     * @brief Updates the policy for the observer.
     * @param policy The new policy.
     */
    virtual void updatePolicy(Policy policy) = 0;

    /**
     * @brief Updates the services for the observer.
     * @param services The new services.
     */
    virtual void updateServices(CityService services) = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures derived class destructors are called correctly.
     */
    virtual ~GovObserver() = default;
};

#endif // GOVOBSERVER_H