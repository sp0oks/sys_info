#include <unistd.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <sys/resource.h>
#include <sys/time.h>

#define OPT_ALL		0
#define OPT_UNAME	1
#define	OPT_UID		2
#define	OPT_PID		3
#define OPT_RUSAGE	4

typedef struct {
	struct utsname unameData;
	pid_t pid, ppid;
	uid_t uid, euid;
	struct rusage rusageSelf, rusageChildren;
} info_t;

long sys_info(int opt, info_t *buf){
	long err = 0;	
	switch (opt){
		case OPT_UNAME: 
			err = uname(&buf->unameData);
			break;
		case OPT_UID:
			buf->uid = getuid();
			buf->euid = geteuid();
			break;
		case OPT_PID:	
			buf->pid = getpid();
			buf->ppid = getppid();
			break;
		case OPT_RUSAGE:
			err = getrusage(RUSAGE_SELF, &buf->rusageSelf);
			err = getrusage(RUSAGE_CHILDREN, &buf->rusageChildren);
			break;
		case OPT_ALL:
			err = uname(&buf->unameData);
			buf->uid = getuid();
			buf->euid = geteuid();
			buf->pid = getpid();
			buf->ppid = getppid();
			err = getrusage(RUSAGE_SELF, &buf->rusageSelf);
			err = getrusage(RUSAGE_CHILDREN, &buf->rusageChildren);
			break;
		default:
			return -1;
	}
	return err;
}
