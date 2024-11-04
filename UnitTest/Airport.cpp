#include "Airport.h"

Airport::Airport(char state, std::string name, char type) : Transportation(state, type) {
    this->name = name;
}

std::string Airport::getAirportName() {
    return name;
}

float Airport::calculateCommute() {
    return 20.0;
}