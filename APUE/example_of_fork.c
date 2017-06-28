/*************************************************************************
    > File Name: example_of_fork.c
    > Author: ma6174
    > Mail: yanch7@163.com 
    > Created Time: Fri 23 Jun 2017 10:36:23 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int global = 6;
char buf[] = "a write to buf";

int main(void)
{
	int var = 7;
	pid_t pid;

	if(write(STDOUT_FILENO, buf, sizeof(buf) -1) != sizeof(buf)-1)
	{
		printf("write error\n");
		exit(1);
	}

	if((pid = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid == 0) //child process
	{
		var++;
		global++;
	}
	else
	{
		sleep(2);
	}

	printf("pid=%ld, glob=%d, var=%d\n", (long)pid, global, var);
	return 0;
}
