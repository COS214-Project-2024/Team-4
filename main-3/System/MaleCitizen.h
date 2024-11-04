#ifndef MALE_CITIZEN_H
#define MALE_CITIZEN_H

#include "Citizen.h"
#include <memory>

class MaleCitizen : public Citizen {
public:
    MaleCitizen(const std::string& name, int age) : Citizen(name, age) {}

    // Implement clone method
    std::shared_ptr<Citizen> clone() const override {
        return std::make_shared<MaleCitizen>(*this);
    }
};

#endif // MALE_CITIZEN_H




