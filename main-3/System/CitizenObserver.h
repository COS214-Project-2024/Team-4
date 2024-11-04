#ifndef CITIZEN_OBSERVER_H
#define CITIZEN_OBSERVER_H

class Citizen; // Forward declaration

class CitizenObserver {
public:
    virtual ~CitizenObserver() = default;
    virtual void update(Citizen* citizen) = 0; // Abstract update method
};

#endif // CITIZEN_OBSERVER_H



