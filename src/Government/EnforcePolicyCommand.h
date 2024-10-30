#ifndef ENFORCEPOLICYCOMMAND_H
#define ENFORCEPOLICYCOMMAND_H

#include "GovCommand.h"
#include "Government.h"
#include "Policy.h"

class EnforcePolicyCommand : public GovCommand {

private:
    Government* government;
    Policy policy;

public:
    EnforcePolicyCommand(Government* gov, Policy pol);

    void execute() override;
    void undo() override;
};

#endif