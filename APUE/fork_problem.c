/*************************************************************************
    > File Name: fork_problem.c
    > Author: ma6174
    > Mail: yanch7@163.com 
    > Created Time: Fri 23 Jun 2017 11:14:07 AM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	int i;
	for(i = 0; i < 2; i++)
	{
		fork();
		printf("-");
	}

	wait(NULL);
	wait(NULL);

	return 0;
}
