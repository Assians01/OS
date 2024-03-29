#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork(); // Create a child process

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This code is executed by the child process
        printf("Child process (PID %d) is running.\n", getpid());
        // Child process exits immediately
        exit(0);
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID %d) is running.\n", getpid());
        // The parent does not wait for the child
        sleep(10); // Sleep for a while
        //call wait(NULL) to collect the exit status of the child process
        printf("Parent process (PID %d) is done.\n", getpid());
    }

    return 0;
}





/* A zombie process is a terminated process that has completed its execution but still has an entry in process table */
