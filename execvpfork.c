#include<stdio.h>
#include<unistd.h>
int main(){
  char *command = "ls";
  char *argument_list[] = {"ls","-l",NULL};
  printf("Before calling execvp()\n");
  if(fork() == 0){ 
     int status_code = execvp(command,argument_list);
     printf("This won't execute unless terminates abnormally!");
     if(status_code == -1){
        printf("Terminated Incorrectly\n");
        return 1;
     }
  }
  else{
     printf("This line will be printed\n");
  }
  return 0;
}