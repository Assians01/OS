//zombie PREVENTION
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    if(pid<0){
        printf("Fork Failed");
    }
    else if(pid == 0){
        printf("Child process is running with PID %d\n",getpid());
        sleep(5);
        printf("Child process is done\n");
    }
    else{
        printf("Parent process is running with PID %d\n",getpid());
        int status;
        wait( status);
        printf("Parent process is done");
    }
    return 0;
}





/* A way to avoid creating zombie processes is to use the wait() system call in the parent process to collect termination status of child process. 
By doing this the parent process ensures that the child process is removed from process table once it has completed its execution */ 
