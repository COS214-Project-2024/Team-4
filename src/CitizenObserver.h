// CitizenObserver.h
#ifndef CITIZENOBSERVER_H
#define CITIZENOBSERVER_H

class Citizen;

class CitizenObserver {
public:
    virtual void update(Citizen* citizen) = 0; // Observer update method
    virtual ~CitizenObserver() = default;
};

#endif // CITIZENOBSERVER_H


