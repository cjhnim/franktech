/*
 * task.h
 *
 *  Created on: 2018. 4. 4.
 *      Author: francis
 */

#ifndef TASK_H_
#define TASK_H_
#include <pthread.h>
int run_task(pthread_startroutine_t task, int *ret_value);
int run_task_nowait(pthread_startroutine_t task, int wait_in_seconds);
#endif /* TASK_H_ */
