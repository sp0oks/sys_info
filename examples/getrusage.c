#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/resource.h>
#include "../src/sys_info.h"

int main(int argc, char** argv){
	info_t dados;
	struct rusage rusageData;
	int err = sys_info(OPT_RUSAGE, &dados);

	char* error = NULL;

	if (argc == 2){
		int type = atoi(argv[1]);
		switch(type) {
			case 1:	rusageData = dados.rusageSelf;
				break;
			case 2: rusageData = dados.rusageChildren;
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

