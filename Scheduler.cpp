#include "Scheduler.h"

Scheduler::Scheduler():
	init_has_run(false)
{

}

void Scheduler::add_task(Task * task)
{
	task_queue.push_back(task);
}

void Scheduler::remove_task(Task * task)
{
	task_queue.erase(
		std::remove(task_queue.begin(), task_queue.end(), task),
		task_queue.end()
	);
}

void Scheduler::run()
{
	if (!task_queue.empty())
	{
		if (task_queue.front()->is_finished())
		{
			task_queue.front()->end();

			task_queue.pop_back();
		}
		else
		{
			if (init_has_run)
				task_queue.front()->execute();
			else
				task_queue.front()->init();
		}
	}
}