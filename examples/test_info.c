#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "../src/sys_info.h"

int main(){
	info_t infoBuf;

	int err = syscall(357, OPT_ALL, &infoBuf);
	if (!err){
		time_t us_cpu_usec_self, sys_cpu_usec_self, us_cpu_usec_child, sys_cpu_usec_child;
		us_cpu_usec_self = infoBuf.rusageSelf.ru_utime.tv_usec;
		sys_cpu_usec_self = infoBuf.rusageSelf.ru_stime.tv_usec;
		us_cpu_usec_child = infoBuf.rusageChildren.ru_utime.tv_usec;
		sys_cpu_usec_child = infoBuf.rusageSelf.ru_stime.tv_usec;

		printf("OS Name: %s\nHostname: %s\nOS Release: %s\nOS Version: %s\nArchitecture: %s\n", 
				infoBuf.unameData.sysname, infoBuf.unameData.nodename, infoBuf.unameData.release,
				infoBuf.unameData.version, infoBuf.unameData.machine);
		printf("Process ID: %d\nParent Process ID:%d\n", infoBuf.pid, infoBuf.ppid);
		printf("User ID: %d\nEffective User ID: %d\n", infoBuf.uid, infoBuf.euid);
		printf("Process' running CPU time:\n\tUser mode: %ld us\n\tKernel mode: %ld us\n", 
				us_cpu_usec_self, sys_cpu_usec_self);
		printf("Child Process' running CPU time:\n\tUser mode: %ld us\n\tKernel mode: %ld us\n", 
				us_cpu_usec_child, sys_cpu_usec_child);
		
	}
	else	perror("sys_info");
	return 0;
}
