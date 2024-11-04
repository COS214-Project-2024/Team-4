// UnsatisfiedState.h

#ifndef UNSATISFIEDSTATE_H
#define UNSATISFIEDSTATE_H

#include "CitizenState.h"

class UnsatisfiedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // UNSATISFIEDSTATE_H

