#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main() {
    // Process ID of the target process to be killed
    pid_t targetProcessID;

    printf("Enter the Process ID of the target process to kill: ");
    scanf("%d", &targetProcessID);

    // Attempt to kill the process with SIGKILL
    if (kill(targetProcessID, SIGKILL) == 0) {
        printf("Process with PID %d killed successfully.\n", targetProcessID);
    } else {
        perror("Failed to kill the process");
    }

    return 0;
}