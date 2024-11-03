#include "Train.h"

Train::Train(char state, std::string line) : Transportation(state) {
    this->line = line;
}

std::string Train::getTrainLine() {
    return line;
}