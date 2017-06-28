/*************************************************************************
    > File Name: myio.c
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Wed 28 Jun 2017 09:18:42 AM CST
 ************************************************************************/

#include "myio.h"

ssize_t readn(int fd, void *buff, size_t nbytes)
{
	ssize_t nread = 0;
	size_t nleft = nbytes;
	char *ptr = buff;

	while(nleft > 0)
	{
		if((nread = read(fd, ptr, nleft)) < 0)
		{
			if(errno == EINTR) nread = 0;
			else return -1;
		}
		else if(nread == 0) break;

		nleft -= nread;
		ptr += nread;
	}

	return (nbytes - nleft);
}

ssize_t writen(int fd, const void* buff, size_t nbytes)
{
	ssize_t nwritten = 0;
	size_t nleft = nbytes;
	const char *ptr = buff;

	while(nleft > 0)
	{
		if((nwritten = write(fd, buff, nleft)) <= 0)
		{
			if(nwritten < 0 && errno == EINTR) nwritten = 0;
			else return -1;
		}

		nleft -= nwritten;
		ptr += nwritten;
	}

	return (nbytes - nleft);
}
