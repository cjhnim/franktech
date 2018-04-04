#include <pthread.h>

pthread_addr_t mythread(pthread_addr_t arg)
{
	int wait_in_seconds = (int) arg;
	pthread_addr_t exit_code = (pthread_addr_t) 7;

	printf("\nI'm a thread[tid:%d], I will return %d\n", pthread_self(), exit_code);

	printf("suspend during %d\n", wait_in_seconds);
	sleep(wait_in_seconds);
	printf("waken\n");

	return exit_code;
}
