// MaleCitizen.cpp

#include "MaleCitizen.h"

MaleCitizen::MaleCitizen(const std::string& name, int age, const std::string& relationshipStatus, const std::string& jobStatus)
    : Citizen(name, age, relationshipStatus, jobStatus) {}

std::shared_ptr<Citizen> MaleCitizen::clone() const {
    return std::make_shared<MaleCitizen>(*this); // Clone the current MaleCitizen
}


