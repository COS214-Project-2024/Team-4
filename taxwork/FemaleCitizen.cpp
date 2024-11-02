
#include "FemaleCitizen.h"

// Constructor Implementation
FemaleCitizen::FemaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle)
    : Citizen(name, age, resStatus, jobTitle) {
    // Additional initialization if necessary
}

// Destructor Implementation
FemaleCitizen::~FemaleCitizen() {
    // Cleanup if necessary
}

// Clone Method Implementation
std::shared_ptr<Citizen> FemaleCitizen::clone() const {
    return std::make_shared<FemaleCitizen>(*this);
}