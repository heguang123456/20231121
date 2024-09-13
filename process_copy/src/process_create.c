#include <process_copy.h>
//#include <pro_copy.c>
int process_create(char * srcfile , char * destfile , int blocksize , int pronum)
{
	pid_t pid;
	int flags = 0;
	for(flags = 0 ; flags < pronum ; flags++){
		pid = fork();
		if(pid < 0)
			break;
	}
	if(pid > 0){
		printf("创建子线程成功\n");
	}else if(pid == 0){
		int pos = flags * blocksize;  // 地址偏移

		char szblocksize[10];         // 临时变量存储块大小
		char szpos[10];

		sprintf(szpos , "%d" , pos);
		sprintf(szblocksize , "%d" , blocksize);

		printf("当前读取位置为:%d , 每次所读文件大小为:%d,当前进程id为:%d" , pos , blocksize , getpid());
		execl("/home/colin/20231121/process_copy/src/pro_copy.c" , "copy" , srcfile , destfile , szpos , szblocksize , NULL);
	}

	return 0;
}
