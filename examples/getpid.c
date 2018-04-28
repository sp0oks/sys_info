#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	pid_t pid, ppid;
	pid = getpid();
	ppid = getppid();

	printf("Current Process ID: %d\nParent Process ID: %d\n", pid, ppid);
	
	return 0;
}
