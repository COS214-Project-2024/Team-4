#ifndef GOVCOMMAND_H
#define GOVCOMMAND_H

#include <string>

class GovCommand {
public:
    GovCommand(const std::string& command);
    void execute();
    std::string getCommand() const;

private:
    std::string command;
};

#endif // GOVCOMMAND_H