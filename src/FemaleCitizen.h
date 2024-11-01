// FemaleCitizen.h

#ifndef FEMALE_CITIZEN_H
#define FEMALE_CITIZEN_H

#include "Citizen.h"

class FemaleCitizen : public Citizen {
public:
    FemaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobStatus);
    std::shared_ptr<Citizen> clone() const override;
};

#endif // FEMALE_CITIZEN_H
