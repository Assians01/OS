#include<stdio.h>
#include<unistd.h>
int main(){
  char *const ps_envp[] = {"PATH = /bin:/user/bin","TERM = console",0};
  printf("Before execl\n");
  execl("/bin/ps","ps","-a",NULL) ;
  printf("After execl\n");
}