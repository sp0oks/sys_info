#include <stdio.h>
#include <errno.h>
#include "../src/sys_info.h"

int main(){
	info_t infobuf;
	int err = sys_info(OPT_UNAME, &infobuf);
	char* error = NULL;
	if (!err){
		printf("OS Name: %s\nHostname: %s\nOS Release: %s\nOS Version: %s\nArchitecture: %s\n", 
			infobuf.unameData.sysname, infobuf.unameData.nodename, infobuf.unameData.release, infobuf.unameData.version, infobuf.unameData.machine);
	}
	else perror("uname:");
	return 0;
}
