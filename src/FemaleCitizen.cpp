// FemaleCitizen.cpp

#include "FemaleCitizen.h"

FemaleCitizen::FemaleCitizen(const std::string& name, int age, const std::string& relationshipStatus, const std::string& jobStatus)
    : Citizen(name, age, relationshipStatus, jobStatus) {}

std::shared_ptr<Citizen> FemaleCitizen::clone() const {
    return std::make_shared<FemaleCitizen>(*this); // Clone the current FemaleCitizen
}

