// LeavingCityState.h

#ifndef LEAVINGCITYSTATE_H
#define LEAVINGCITYSTATE_H

#include "CitizenState.h"

class LeavingCityState : public CitizenState {
public:
    void handleState(Citizen& citizen) const override;
};

#endif // LEAVINGCITYSTATE_H

