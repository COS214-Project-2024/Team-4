#include "PublicTransit.h"

PublicTransit::PublicTransit(char state, std::string route) : Transportation(state) {
    this->route = route;
}

std::string PublicTransit::getRoute() {
    return route;
}