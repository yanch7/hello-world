/*************************************************************************
    > File Name: figure_11_2.c
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Mon 26 Jun 2017 01:31:25 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

void print_pids(const char*);
void *thread_func(void *arg);

int main(void)
{
	int error;
	pthread_t tid;

	error = pthread_create(&tid, NULL, thread_func, (void*)("new thread:"));
	if(error != 0)
	{
		printf("cannot create thread\n");
		exit(1);
	}

	print_pids("main thread:\n");
	sleep(1);
	return 0;
}

void print_pids(const char* s)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s pid is %ld, tid is %ld\n", s, (long)pid, (long)tid );
}

void *thread_func(void *arg)
{
	char *s = (char *)arg;
	print_pids(s);
}
