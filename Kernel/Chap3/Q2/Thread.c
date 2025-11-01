#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/unistd.h>
#include <pthread.h>

/*
 * Test code to see how exit affects the entire process in a child thread
 */

void *t_function_exec(void *data)
{
	int time;
	time = *((int *)data);
	sleep(time);
	execl("/usr/bin/ls", "ls", (char *)0);
}

void *t_function_exit(void *data)
{
	int time;
	time = *((int *)data);
	sleep(time);
	exit(0);
}

int main(void)
{
	int pid, status;
	int exec_time = 2;
	int exit_time = 1;
	pthread_t p_thread[2];

	if((pid == pthread_create(&p_thread[0], NULL, t_function_exec, (void *)&exec_time)) < 0)
	{
		perror("exec thread create error : ");
		exit(1);
	}
	if((pid == pthread_create(&p_thread[1], NULL, t_function_exit, (void *)&exit_time)) < 0)
	{
		perror("exit thread create error : ");
		exit(1);
	}
	pthread_join(p_thread[1], (void **)&status);
	pthread_join(p_thread[0], (void **)&status);

	return 0;
}
