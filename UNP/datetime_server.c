/*************************************************************************
    > File Name: datetime_server.c
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Wed 28 Jun 2017 10:05:03 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include "myio.h"

#define MAX_LEN 1024

int main(int argc, char** argv)
{
	int listenfd, connfd;
	socklen_t len;
	struct sockaddr_in servaddr, cliaddr;
	char buff[MAX_LEN];
	time_t ticks;

	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd < 0)
	{
		printf("create listen socket failed\n");
		exit(1);
	}

	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(8086);
	if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(struct sockaddr)) < 0)
	{
		printf("bind error\n");
		exit(1);
	}

	if(listen(listenfd, 5) < 0)
	{
		printf("listen error\n");
		exit(1);
	}

	for(;;)
	{
		len = sizeof(cliaddr);
		connfd = accept(listenfd, (struct sockaddr*)&cliaddr, &len);
		if(connfd < 0)
		{
			printf("accept error\n");
			exit(1);
		}

		printf("connection from %s, port %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, buff, sizeof(buff)), ntohs(cliaddr.sin_port));
		snprintf(buff, sizeof(buff), "%.24s\r\n", ctime(&ticks));
		writen(connfd, buff, strlen(buff));

		close(connfd);
	}
}
