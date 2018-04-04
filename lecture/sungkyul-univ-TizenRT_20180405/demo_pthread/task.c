
#include "task.h"

int run_task(pthread_startroutine_t task, int *ret_value)
{
	pthread_t thread;

	int r = pthread_create(&thread, 0, task, 0);
	if(r != 0)
		return r;

	pthread_addr_t exit_code = 0;
	pthread_join(thread, &exit_code);

	*ret_value = (int)exit_code;

	return 0;
}

int run_task_nowait(pthread_startroutine_t task, int task_argument)
{
	pthread_t thread;

	return pthread_create(&thread, 0, task, (pthread_addr_t)task_argument);
}
