/*************************************************************************
    > File Name: myio.h
    > Author: yanchao
    > Mail: yanch7@163.com 
    > Created Time: Wed 28 Jun 2017 09:15:10 AM CST
 ************************************************************************/

#ifndef MYIO_H_
#define MYIO_H_

#include <unistd.h>
#include <errno.h>

ssize_t readn(int fd, void *buff, size_t nbytes);
ssize_t writen(int fd, const void* buff, size_t nbytes);

#endif
