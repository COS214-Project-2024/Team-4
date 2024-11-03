#ifndef GOVOBSERVER_H
#define GOVOBSERVER_H

class Policy; // Forward declaration
class CityService; // Forward declaration

// GovObserver class
// This is an abstract base class for observers that monitor government changes
class GovObserver {
public:
    // Updates the tax rate for the observer
    virtual void updateTaxRate(double rate) = 0;

    // Updates the policy for the observer
    virtual void updatePolicy(Policy policy) = 0;

    // Updates the services for the observer
    virtual void updateServices(CityService services) = 0;

    // Virtual destructor
    // Ensures derived class destructors are called correctly
    virtual ~GovObserver() = default;
};

#endif