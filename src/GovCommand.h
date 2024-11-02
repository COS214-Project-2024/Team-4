#ifndef GOVCOMMAND_H
#define GOVCOMMAND_H
//GOV COMMAND
class GovCommand {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~GovCommand() = default;
};

#endif
