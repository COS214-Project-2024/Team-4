// CitizenObserver.h

#ifndef CITIZENOBSERVER_H
#define CITIZENOBSERVER_H

class Citizen;

class CitizenObserver {
public:
    virtual void update(Citizen* citizen) = 0; // Pure virtual function to respond to citizen updates
    virtual ~CitizenObserver() = default;
};

#endif // CITIZENOBSERVER_H



