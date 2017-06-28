/*************************************************************************
    > File Name: datetime_client.c
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Wed 28 Jun 2017 10:53:05 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<arpa/inet.h>
#include "myio.h"

int main(int argc, char** argv)
{
	int connfd;
	struct sockaddr_in server;
	socklen_t len;
	char buff[200];

	connfd = socket(AF_INET, SOCK_STREAM, 0);
	if(connfd < 0)
	{
		printf("socket error\n");
		exit(1);
	}

	memset(&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_port = htons(8086);
	len = sizeof(server);

	if(connect(connfd, (struct sockaddr*)&server, len) < 0)
	{
		printf("connect error!\n");
		exit(1);
	}

	readn(connfd, buff, sizeof(buff));
	printf("%s\n", buff);
	close(connfd);
	return 0;
}
