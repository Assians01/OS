#include<stdio.h>
#include<unistd.h>
void main(){
 int pid;
 pid=fork();
 pid=fork();
 pid=fork();
 
  printf("\n PID=%d PPID=%d\n",getpid(),getppid());
  sleep(5);

}
