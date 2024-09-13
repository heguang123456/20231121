#include <process_copy.h>
#include <sys/wait.h>
void process_wait(void)
{
	pid_t zpid;
	while((zpid = waitpid(-1 , 0 , WNOHANG)) != -1){
		if(zpid > 0){
				printf("已杀死的僵尸进程id = %d\n" , zpid);
			}
	}
}
