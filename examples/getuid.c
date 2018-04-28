#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	
	uid_t uid, euid;
	uid = getuid();
	euid = geteuid();

	printf("Real user ID: %d\nEffective user ID: %d\n", uid, euid);
	
	return 0;
}
