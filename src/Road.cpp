#include "Road.h"

Road::Road(char state, std::string roadName) : Transportation(state) {
    this->roadName = roadName;
}

// float Road::calculateCommute() {
//     return getTrafficFlow();
// }

std::string Road::getName() {
    return this->roadName;
} 