// MaleCitizen.h

#ifndef MALECITIZEN_H
#define MALECITIZEN_H

#include "Citizen.h"

class MaleCitizen : public Citizen {
public:
    MaleCitizen(const std::string& name = "John Doe", int age = 30,
                const std::string& relationshipStatus = "Single", const std::string& jobStatus = "Unemployed");

    // Override clone to return a copy of MaleCitizen
    std::shared_ptr<Citizen> clone() const override;
};

#endif // MALECITIZEN_H



