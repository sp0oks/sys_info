#define _GNU_SOURCE
#include <linux/unistd.h>
#include <linux/linkage.h>
#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/resource.h>
#include <linux/time.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>

#define OPT_ALL		0
#define OPT_UNAME	1
#define	OPT_UID		2
#define	OPT_PID		3
#define OPT_RUSAGE	4

/*typedef struct {
	struct new_utsname unameData;
	pid_t pid, ppid;
	uid_t uid, euid;
	struct rusage rusageSelf, rusageChildren;
} info_t;*/

asmlinkage long sys_info(int opt, info_t *buf){
	long err = 0;	
	switch (opt){
		case OPT_UNAME: 
			err = sys_uname(&buf->unameData);
			break;
		case OPT_UID:
			buf->uid = sys_getuid();
			buf->euid = sys_geteuid();
			break;
		case OPT_PID:	
			buf->pid = sys_getpid();
			buf->ppid = sys_getpid();
			break;
		case OPT_RUSAGE:
			err = sys_getrusage(RUSAGE_SELF, &buf->rusageSelf);
			err = sys_getrusage(RUSAGE_CHILDREN, &buf->rusageChildren);
			break;
		case OPT_ALL:
			err = sys_uname(&buf->unameData);
			buf->uid = sys_getuid();
			buf->euid = sys_geteuid();
			buf->pid = sys_getpid();
			buf->ppid = sys_getppid();
			err = sys_getrusage(RUSAGE_SELF, &buf->rusageSelf);
			err = sys_getrusage(RUSAGE_CHILDREN, &buf->rusageChildren);
			break;
		default:
			return -1;
	}
	return err;
}
