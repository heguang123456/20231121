/***********************************************************************************
    > File Name: copy.c
    > Author: heguang123456
    > Mail: 2382888309@qq.com 
    > Created Time: 2024年09月10日 星期二 20时04分10秒
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <pthread.h>
#include <signal.h>
int pram_check(int argc, char * srcfile , int pronum);
int block_cur(char * srcfile , int pronum);
int process_create(char * srcfile , char * destfile , int blocksize , int pronum);
void process_wait(void);//父进程阻塞回收僵尸
int pro_copy(char * srcfile , char * destfile , int pos , int blocksize);
