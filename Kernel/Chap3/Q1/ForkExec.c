#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t pid;
	int status;

	if((pid=fork()) < 0) {
		perror("fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		printf("Before exec\n");
		execl("/usr/bin/ls", "ls", (char *)0);
		printf("After exec\n");
	}
	else
	{
		printf("Parent\n");
		pid = wait(&status);
	}
	return 0;
}
