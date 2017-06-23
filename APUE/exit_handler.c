/*************************************************************************
    > File Name: exit_handler.c
    > Author: ma6174
    > Mail: yanch7@163.com 
    > Created Time: Fri 23 Jun 2017 09:41:33 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

static void my_exit1(void);
static void my_exit2(void);

int main(void)
{
	if(atexit(my_exit2) != 0)
	{
		printf("cannot register my_exit2\n");
		exit(2);
	}

	if(atexit(my_exit1) != 0)
	{
		printf("cannot register my_exit1\n");
		exit(1);
	}

	if(atexit(my_exit2) != 0)
	{
		printf("cannot register my_exit2\n");
		exit(2);
	}

	printf("main\n");
	return 0;
}

static void my_exit1(void)
{
	printf("my_exit1\n");
}

static void my_exit2(void)
{
	printf("my_exit2\n");
}
