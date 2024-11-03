#ifndef FEMALE_CITIZEN_H
#define FEMALE_CITIZEN_H

#include "Citizen.h"
#include <memory>

class FemaleCitizen : public Citizen {
public:
    FemaleCitizen(const std::string& name, int age) : Citizen(name, age) {}

    // Implement clone method
    std::shared_ptr<Citizen> clone() const override {
        return std::make_shared<FemaleCitizen>(*this);
    }
};

#endif // FEMALE_CITIZEN_H



