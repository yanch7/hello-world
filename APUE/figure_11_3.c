/*************************************************************************
    > File Name: figure_11_3.c
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Mon 26 Jun 2017 02:02:28 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* thread_func(void *arg)
{
	pthread_t tid;
	int retcode = *((int*)arg);
	tid = pthread_self();
	printf("thread id is %ld, retcode is %d\n", (long)tid, retcode);
	pthread_exit(arg);
}

int main(void)
{
	pthread_t tid1, tid2;
	int ret1 = 111;
	int ret2 = 222;
	int error;
	void *return_code;

	error = pthread_create(&tid1, NULL, thread_func, (void *)&ret1);
	if(error != 0)
	{
		printf("cannot create thread1, error %d\n", error);
		exit(error);
	}

	error = pthread_create(&tid2, NULL, thread_func, (void *)&ret2);
	if(error != 0)
	{
		printf("cannot create thread2, error %d\n", error);
		exit(error);
	}

	pthread_join(tid1, &return_code);
	printf("thread1 exit code:%d\n", *((int*)return_code));
	pthread_join(tid2, &return_code);
	printf("thread2 exit code:%d\n", *((int*)return_code));
	return 0;
}
