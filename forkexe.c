#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	printf("main: pid=%d\n",getpid());
	pid_t child;
	child = fork();
	if (child == 0){
		sleep(1);
		printf("I am the child (pid=%d)\n", getpid());
		sleep(1);		
	}
	else {
		sleep(1);
		printf("I am the parent (pid=%d), with child  pid=%d\n",getpid(),child);
		sleep(1);
	}
	return 0;
}

