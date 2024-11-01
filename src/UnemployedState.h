// UnemployedState.h

#ifndef UNEMPLOYED_STATE_H
#define UNEMPLOYED_STATE_H

#include "CitizenState.h"

class UnemployedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // UNEMPLOYED_STATE_H

