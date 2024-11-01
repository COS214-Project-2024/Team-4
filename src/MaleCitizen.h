// MaleCitizen.h

#ifndef MALE_CITIZEN_H
#define MALE_CITIZEN_H

#include "Citizen.h"

class MaleCitizen : public Citizen {
public:
    MaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobStatus);
    std::shared_ptr<Citizen> clone() const override;
};

#endif // MALE_CITIZEN_H
