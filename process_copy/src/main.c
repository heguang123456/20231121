#include <process_copy.h>
int main(int argc , char * argv[])
{
	// 检验参数个数，源文件，进程数
	
	int pronumber = 0;
	pronumber = atoi(argv[3]);
	if(0 == pronumber){
		pronumber = 5;
	}
	pram_check(argc , argv[1] , pronumber);
	
	// 每个块的大小
	int nblocksize = block_cur(argv[1] , pronumber);
	// 创建进程数
	process_create(argv[1] , argv[2] , nblocksize , pronumber);
	// 处理僵尸进程
	process_wait();
	return 0;
}
