#include "GovCommand.h"


// Executes the command
// This method should be overridden by derived classes to implement specific command execution logic
void GovCommand::execute() {
    throw "Not yet implemented";
}

// Undoes the command
// This method should be overridden by derived classes to implement specific command undo logic
void GovCommand::undo() {
    throw "Not yet implemented";
}

// Gets the name of the command
// This method should be overridden by derived classes to provide the command name
std::string GovCommand::getName() const {
    return "Unnamed Command";
}

// Gets the description of the command
// This method should be overridden by derived classes to provide the command description
std::string GovCommand::getDescription() const {
    return "No description available.";
}

// Checks if the command can be executed
// This method should be overridden by derived classes to provide execution validation
bool GovCommand::canExecute() const {
    return true;
}

double GovCommand::returnVal() {
    return 0.0;
}

