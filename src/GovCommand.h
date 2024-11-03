#ifndef GOVCOMMAND_H
#define GOVCOMMAND_H

// GovCommand class
// This is an abstract base class for government commands
class GovCommand {
public:
    // Executes the command
    // This method should be overridden by derived classes to implement specific command execution logic
    virtual void execute() = 0;

    // Undoes the command
    // This method should be overridden by derived classes to implement specific command undo logic
    virtual void undo() = 0;

    // Virtual destructor
    // Ensures derived class destructors are called correctly
    virtual ~GovCommand() = default;
};

#endif