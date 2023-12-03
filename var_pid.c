#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid,i =10;
    pid = fork();
    if(pid<0)
       printf("Fork Failed");
    else if(pid == 0){
        printf("Child Process Id= %d\t Parent Process Id= %d\n",getpid(),getppid());
    //    sleep(5);
        printf("In child process = %d\n",i);
        printf("Child Process Id= %d\t Parent Process Id= %d\n",getpid(),getppid());
    } 
    else{
        printf("In parent process = %d\n",i+10);
        printf("Child Process Id= %d\t Parent Process Id= %d\n",getpid(),getppid());
    }
    sleep(10);
}
