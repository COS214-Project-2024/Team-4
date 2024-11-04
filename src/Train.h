#ifndef TRAIN_H
#define TRAIN_H

#include "Transportation.h"

class Train : public Transportation {
    private:
        std::string line;

    public:
        Train(char state, std::string line, char type);
        float calculateCommute();
        std::string getLine();

};

#endif