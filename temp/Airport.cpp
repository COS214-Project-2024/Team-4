#include "Airport.h"

Airport::Airport(char state, std::string name) : Transportation(state) {
    this->name = name;
}

std::string Airport::getAirportName() {
    return name;
}