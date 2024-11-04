/**
 * @file GovCommand.cpp
 * @brief Implementation of the GovCommand class.
 * @version 1.0
 * 
 * This file contains the implementation of the GovCommand class, which serves as a base class for
 * various government-related commands. Derived classes should override the methods to provide
 * specific command execution logic.
 */

#include "GovCommand.h"

/**
 * @brief Executes the command.
 * 
 * This method should be overridden by derived classes to implement specific command execution logic.
 * @throws const char* Exception indicating the method is not yet implemented.
 */
void GovCommand::execute() {
    throw "Not yet implemented";
}

/**
 * @brief Undoes the command.
 * 
 * This method should be overridden by derived classes to implement specific command undo logic.
 * @throws const char* Exception indicating the method is not yet implemented.
 */
void GovCommand::undo() {
    throw "Not yet implemented";
}

/**
 * @brief Gets the name of the command.
 * 
 * This method should be overridden by derived classes to provide the command name.
 * @return The name of the command.
 */
std::string GovCommand::getName() const {
    return "Unnamed Command";
}

/**
 * @brief Gets the description of the command.
 * 
 * This method should be overridden by derived classes to provide the command description.
 * @return The description of the command.
 */
std::string GovCommand::getDescription() const {
    return "No description available.";
}

/**
 * @brief Checks if the command can be executed.
 * 
 * This method should be overridden by derived classes to provide execution validation.
 * @return True if the command can be executed, false otherwise.
 */
bool GovCommand::canExecute() const {
    return true;
}

/**
 * @brief Returns a value associated with the command.
 * 
 * This method can be overridden by derived classes to return a specific value.
 * @return A double value associated with the command.
 */
double GovCommand::returnVal() {
    return 0.0;
}