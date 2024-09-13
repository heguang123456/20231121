#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/fcntl.h>
int main(int argc, char* argv[])
{
	// 检验参数
	if(argc < 4){
		perror("参数不足");
		exit(0);
	}

	// 打开源文件--read
	int srcfd = open(argv[1],O_RDONLY);
	if(srcfd == -1){
		perror("open failed");
		exit(0);
	}
	
	// 打开目标文件--write
	int desfd = open(argv[2],O_WRONLY|O_CREAT,0664);
	if(desfd == -1){
		perror("write failed");
		exit(0);
	}

	// 移动源文件指针
	int npos = atoi(argv[3]);
	lseek(srcfd,npos,SEEK_END);
	
	// 移动目标文件指针
	lseek(desfd,npos,SEEK_END);
	
	// 读源文件内容
	int nbuffsize = atoi(argv[4]);
	char szbuff[nbuffsize];
	int readlen = read(srcfd,szbuff,nbuffsize);
	if(readlen == -1){
		perror("read failed");
		exit(0);
	}
	write(desfd,szbuff,readlen);
	close(srcfd);
	close(desfd);
	return 0;
}
