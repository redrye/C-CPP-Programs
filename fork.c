#include <stdio.h>

int main() {
	int pid = fork();
	int c = 5;
	printf("c = %d, child %d of parent %d\n", c, getpid(), pid);
	if(pid == 0) {
		fork();
		c+=10;
		printf("c = %d, child %d of parent %d\n", c, getpid(), pid);
	}
	else {
		c+=5;
		printf("c = %d, child %d of parent %d\n", c, getpid(), pid);
	}
	return 0;
}
