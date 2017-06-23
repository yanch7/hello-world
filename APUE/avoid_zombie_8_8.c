/*************************************************************************
    > File Name: avoid_zombie_8_8.c
    > Author: ma6174
    > Mail: yanch7@163.com 
    > Created Time: Fri 23 Jun 2017 01:36:35 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
	pid_t child, grandchild;

	if((child = fork()) < 0)
	{
		printf("fork error\n");
		exit(1);
	}
	else if(child == 0)
	{
		if((grandchild = fork()) < 0)
		{
			printf("fork grandchild error\n");
			exit(1);
		}
		else if(grandchild > 0)
		{
			printf("child process:%ld exit, parent is: %ld\n", (long)getpid(), (long)getppid());
			exit(0);
		}
		else
		{
			sleep(2);
			printf("grandchild process:%ld exit, parent is: %ld\n", (long)getpid(), (long)getppid());
			exit(0);
		}
	}
	else
	{
		if(waitpid(child, NULL, 0) != child)
		{
			printf("wait child error\n");
			exit(1);
		}
	}

	printf("process:%ld exit, parent is: %ld\n", (long)getpid(), (long)getppid());
	return 0;
}
