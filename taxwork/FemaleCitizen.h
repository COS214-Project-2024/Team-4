// FemaleCitizen.h

#ifndef FEMALECITIZEN_H
#define FEMALECITIZEN_H

#include "Citizen.h"

class FemaleCitizen : public Citizen {
public:
    FemaleCitizen(const std::string& name = "Jane Doe", int age = 28,
                  const std::string& relationshipStatus = "Single", const std::string& jobStatus = "Unemployed");

    // Override clone to return a copy of FemaleCitizen
    std::shared_ptr<Citizen> clone() const override;
};

#endif // FEMALECITIZEN_H


