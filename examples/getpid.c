#include <stdio.h>
#include "../src/sys_info.h"

int main(){
	info_t dados;
	sys_info(OPT_PID, &dados);
	
	printf("Current Process ID: %d\nParent Process ID: %d\n", dados.pid, dados.ppid);
	
	return 0;
}
