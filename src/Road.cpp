#include "Road.h"

Road::Road(char state, std::string roadName, char type) : Transportation(state, type) {
    this->roadName = roadName;
}

float Road::calculateCommute() {
    return 10 * (1+getTrafficFlow());
}

std::string Road::getName() {
    return this->roadName;
} 