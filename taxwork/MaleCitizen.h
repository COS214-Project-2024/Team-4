// MaleCitizen.h

#ifndef MALECITIZEN_H
#define MALECITIZEN_H

#include "Citizen.h"

class MaleCitizen : public Citizen {
public:
    MaleCitizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobTitle);
    virtual ~MaleCitizen() override;

    virtual std::shared_ptr<Citizen> clone() const override;
};

#endif // MALECITIZEN_H


