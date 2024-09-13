#include <process_copy.h>
int block_cur(char * srcfile , int pronum)
{
	// 查看源文件大小
	int srcfd = open(srcfile , O_RDONLY);
	if(srcfd == -1){
		perror("cutting oepn failed");
		return -1;
	}
	int filesize = lseek(srcfd , 0 , SEEK_END);
	if(filesize == -1){
		perror("filesize failed");
		close(srcfd);
		return -1;
	}
	int blocksize = 0;
	if(filesize % pronum == 0){
		blocksize = filesize / pronum;
	}else{
		blocksize = filesize / pronum + 1;
	}
	close(srcfd);
	return blocksize;
}
