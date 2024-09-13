#include <process_copy.h>
int pram_check(int argc , char * srcfile , int pronum)
{
	if(argc < 3){
		perror("参数错误");
		exit(0);
	}

	if(access(srcfile , F_OK) == -1){
		perror("源文件不存在");
		exit(0);
	}
	if(pronum < 0 || pronum > 100){
		perror("进程数量请在(0,100)内");
		exit(0);
	}
	return 0;
}
