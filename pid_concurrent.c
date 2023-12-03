#include<stdio.h>
#include<unistd.h>
void main(){
 int pid;
 pid=fork();
 if(pid==0){
  printf("\nchild PID=%d child PPID=%d\n",getpid(),getppid());
 }
 else if(pid>0){
  printf("\nparent PID=%d parent PPID=%d\n",getpid(),getppid());
 }else{
  printf("Error");
 }
}
