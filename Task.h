#ifndef TASK_H
#define TASK_H

class Task
{
public:
	Task();

	virtual void init();
	virtual void execute();
	virtual bool is_finished();
	virtual void end();
	virtual void interrupted();
};

#endif