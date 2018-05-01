#include <stdio.h>
#include "../src/sys_info.h"

int main(){
	info_t dados;
	sys_info(OPT_UID, &dados);
	printf("Real user ID: %d\nEffective user ID: %d\n", dados.uid, dados.euid);
	
	return 0;
}
