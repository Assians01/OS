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
        printf("Child process (PID %d) is running with parent(PID %d).\n", getpid(),getppid());
        sleep(10); // Simulate some work
        printf("Child process (PID %d) is done with parent(PID %d).\n", getpid(),getppid());
        printf("Child process is done");
    } else {
        // This code is executed by the parent process
        printf("Parent process (PID %d) is running with parent(PID %d).\n", getpid(),getppid());
        // The parent process exits immediately, creating an orphan child process
        printf("Parent process is done");
        exit(0);
    }

    return 0;
}





/* an orphan process is a child process that continues to execute after its parent process has terminated. When a parent process has created a child and
then exits without waiting for the child to complete the child becomes an orphan. In the output the parent prints the PID and terminates. The child process 
prints the PID simulates some work with sleep(10) and then prints the message "child process is done". This shows that the child process continues to execute 
after parent process has exit. */
