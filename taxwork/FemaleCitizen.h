#ifndef FEMALECITIZEN_H
#define FEMALECITIZEN_H

#include "Citizen.h"

class FemaleCitizen : public Citizen {
public:
    FemaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle);
    virtual ~FemaleCitizen() override;

    virtual std::shared_ptr<Citizen> clone() const override;
};

#endif // FEMALECITIZEN_H


