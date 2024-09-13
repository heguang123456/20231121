/***********************************************************************************
  > File Name: pro_copy.c
  > Author: heguang123456
  > Mail: 2382888309@qq.com 
  > Created Time: 2024年09月11日 星期三 22时07分17秒
 ************************************************************************/
#include <process_copy.h>
int process_copy(char * srcfile , char * destfile , int pos , int blocksize)
{
	if(access(srcfile , F_OK) == -1){
		perror("access failed");
	}
	int sfd,dfd;
	char buf[blocksize];
	sfd = open(srcfile , O_RDONLY);
	dfd = open(destfile , O_WRONLY|O_CREAT , 0664);
	lseek(sfd , pos , SEEK_SET);
	lseek(dfd , pos , SEEK_SET);

	int len = read(sfd , buf , sizeof(buf));
	write(dfd , buf , len);
	close(sfd);
	close(dfd);
	return 1;
}

