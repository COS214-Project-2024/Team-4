// MaleCitizen.cpp

#include "MaleCitizen.h"

// Constructor Implementation
MaleCitizen::MaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle)
    : Citizen(name, age, resStatus, jobTitle) {
    // Additional initialization if necessary
}

// Destructor Implementation
MaleCitizen::~MaleCitizen() {
    // Cleanup if necessary
}

// Clone Method Implementation
std::shared_ptr<Citizen> MaleCitizen::clone() const {
    return std::make_shared<MaleCitizen>(*this);
}


