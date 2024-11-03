#ifndef GOVCOMMAND_H
#define GOVCOMMAND_H

class GovCommand {
public:

	virtual void  execute()=0;
	virtual void undo()=0;
	virtual double returnVal()=0;
};

#endif
