#include "EnforcePolicyCommand.h"

EnforcePolicyCommand::EnforcePolicyCommand(Government* gov, Policy pol)
    : government(gov), policy(pol) {}

void EnforcePolicyCommand::execute() {
    government->enforcePolicy(policy);
}

void EnforcePolicyCommand::undo() {
    // Implement undo logic if applicable
}

double EnforcePolicyCommand::returnVal() {
	return 0.0;
}
