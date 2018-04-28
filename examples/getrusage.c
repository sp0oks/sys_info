#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <errno.h>

int main(int argc, char** argv){
	struct rusage rusageData;
	int err, type;
	char* error = NULL;

	if (argc == 2){
		type = atoi(argv[1]);
		switch(type) {
			case 1:	err = getrusage(RUSAGE_SELF, &rusageData);
				break;
			case 2: err = getrusage(RUSAGE_CHILDREN, &rusageData);
				break;
			default:
				return -1;
		}
		if (!err){
			time_t us_cpu_usec, sys_cpu_usec;
			char *type_msg;

			us_cpu_usec = rusageData.ru_utime.tv_usec;
			sys_cpu_usec = rusageData.ru_stime.tv_usec;
			type_msg = (type == 1) ? "Process" : "Children Processes";

			printf("%s' running CPU time:\n\tUser mode: %ld us\n\tKernel mode: %ld us\n", 
					type_msg, us_cpu_usec, sys_cpu_usec);
		}
		else perror(error);
	}
	return 0;
}
