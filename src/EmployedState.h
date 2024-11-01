// EmployedState.h

#ifndef EMPLOYED_STATE_H
#define EMPLOYED_STATE_H

#include "CitizenState.h"

class EmployedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // EMPLOYED_STATE_H

