#include "Train.h"

Train::Train(char state, std::string line, char type) : Transportation(state, type) {
    this->line = line;
}

std::string Train::getLine() {
    return line;
}