// CitizenState.h

#ifndef CITIZEN_STATE_H
#define CITIZEN_STATE_H

class Citizen;

class CitizenState {
public:
    virtual ~CitizenState() = default;
    virtual void handleState(Citizen& citizen) const = 0;
};

#endif // CITIZEN_STATE_H

