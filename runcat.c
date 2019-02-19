#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
  printf("'shell' is running\n");
  pid_t child_pid;
	
  child_pid = fork();
  
  if (child_pid == 0){
  printf("child started\n");
  execl("/bin/cat","cat",argv[1],NULL);
  printf("child ended\n");
  return 3;
  }else{
    printf("parent\n");
    int child_status;
    waitpid(child_pid,&child_status,0);
    printf("child exited with status %d\n", 0xF & (child_status/256));
  }
  return 0;
}
