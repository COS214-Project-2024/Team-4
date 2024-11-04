// EmployedState.h

#ifndef EMPLOYEDSTATE_H
#define EMPLOYEDSTATE_H

#include "CitizenState.h"

class EmployedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // EMPLOYEDSTATE_H


