#include <sys/syscall.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <linux/sched/types.h>
#include <linux/sched.h>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Usage: ./Sched <Scheduler: F[FIFO], R[RoundRobin], D[DeadLine]>\n");
		exit(1);
	}
	
	// Setting Variable for SysCall
	int policy = 0;
	struct sched_attr attr = {};
	pid_t pid;
	
	if(argv[1][0] == 'F')
		policy = SCHED_FIFO;
	else if (argv[1][0] == 'R')
		policy = SCHED_RR;
	else if (argv[1][0] == 'D')
		policy == SCHED_DEADLINE;
	else
	{
		printf("Usage: ./Sched <Scheduler: F[FIFO], R[RoundRobin], D[DeadLine]>\n");
		exit(1);
	}
	attr.size = sizeof(struct sched_attr);
	attr.sched_policy = policy;
	attr.sched_flags = 0;
	attr.sched_nice = 0;
	if(policy == SCHED_FIFO || policy == SCHED_RR)
		attr.sched_priority = 1;
	else
		attr.sched_priority = 0;
	if(policy == SCHED_DEADLINE)
	{
		attr.sched_runtime = 100000;
		attr.sched_deadline = 110000;
		attr.sched_period = 120000;
	}
	else
	{
		attr.sched_runtime = 0;
		attr.sched_deadline = 0;
		attr.sched_period = 0;
	}
	attr.sched_util_min = 0;
	attr.sched_util_max = 0;
	pid = syscall(SYS_gettid);
	
	// Call SysCall
	if(syscall(SYS_sched_setattr, pid, &attr, 0) < 0)
	{
		perror("Error: Setattr");
		exit(1);
	}

	// Running Test Logic
	printf("Start\n");

	for(int i = 0; i < 1000000; ++i)
	{
		if(i % 100000 == 0)
			sleep(1);
	}
	
	printf("End\n");

	return 0;
}
