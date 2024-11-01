// SatisfiedState.h

#ifndef SATISFIEDSTATE_H
#define SATISFIEDSTATE_H

#include "CitizenState.h"

class SatisfiedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // SATISFIEDSTATE_H

