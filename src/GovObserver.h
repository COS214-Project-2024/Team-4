#ifndef GOVOBSERVER_H
#define GOVOBSERVER_H

class Policy; // Forward declaration
class CityService; // Forward declaration

class GovObserver {
public:
    virtual void updateTaxRate(double rate) = 0;
    virtual void updatePolicy(Policy policy) = 0;
    virtual void updateServices(CityService services) = 0;
};

#endif