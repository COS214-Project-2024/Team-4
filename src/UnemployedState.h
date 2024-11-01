// UnemployedState.h

#ifndef UNEMPLOYEDSTATE_H
#define UNEMPLOYEDSTATE_H

#include "CitizenState.h"

class UnemployedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // UNEMPLOYEDSTATE_H

