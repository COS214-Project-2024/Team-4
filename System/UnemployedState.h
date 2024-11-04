// UnemployedState.h

#ifndef UNEMPLOYEDSTATE_H
#define UNEMPLOYEDSTATE_H

#include "CitizenState.h"
#include <algorithm>
#include <iostream>

class UnemployedState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // UNEMPLOYEDSTATE_H

