/**
 * @file GovCommand.h
 * @brief Definition of the GovCommand class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the GovCommand class, which serves as a base class for
 * various government-related commands. Derived classes should override the methods to provide
 * specific command execution logic.
 */

#ifndef GOVCOMMAND_H
#define GOVCOMMAND_H

#include <string>

/**
 * @class GovCommand
 * @brief Abstract base class for government commands.
 * 
 * This class serves as a base class for various government-related commands. Derived classes should
 * override the methods to provide specific command execution logic.
 */
class GovCommand {
public:
    /**
     * @brief Executes the command.
     * 
     * This method should be overridden by derived classes to implement specific command execution logic.
     */
    virtual void execute() = 0;

    /**
     * @brief Undoes the command.
     * 
     * This method should be overridden by derived classes to implement specific command undo logic.
     */
    virtual void undo() = 0;

    /**
     * @brief Returns a value associated with the command.
     * 
     * This method can be overridden by derived classes to return a specific value.
     * @return A double value associated with the command.
     */
    virtual double returnVal() = 0;
    
    /**
     * @brief Gets the name of the command.
     * 
     * This method should be overridden by derived classes to provide the command name.
     * @return The name of the command.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Gets the description of the command.
     * 
     * This method should be overridden by derived classes to provide the command description.
     * @return The description of the command.
     */
    virtual std::string getDescription() const = 0;

    /**
     * @brief Checks if the command can be executed.
     * 
     * This method should be overridden by derived classes to provide execution validation.
     * @return True if the command can be executed, false otherwise.
     */
    virtual bool canExecute() const = 0;

    /**
     * @brief Virtual destructor.
     * 
     * Ensures derived class destructors are called correctly.
     */
    virtual ~GovCommand() = default;
};

#endif // GOVCOMMAND_H