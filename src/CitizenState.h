// CitizenState.h

#ifndef CITIZENSTATE_H
#define CITIZENSTATE_H

class Citizen;

class CitizenState {
public:
    virtual void handleState(Citizen& citizen) const = 0;
    virtual ~CitizenState() = default;
};

#endif // CITIZENSTATE_H


