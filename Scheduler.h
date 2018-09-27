#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <deque>
#include "Task.h"

class Scheduler
{
public:
	Scheduler();
	void add_task(Task * task);
	void remove_task(Task * task);

	void run();
private:
	std::deque<Task *> task_queue;

	bool init_has_run;
};

#endif