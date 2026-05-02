#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }

    if (pid == 0) {
        printf("Child exiting. PID: %d\n", getpid());
        exit(0);
    }

    printf("Parent sleeping 10s. Child (PID %d) is now zombie.\n", pid);
    printf("Run: ps -l | grep Z\n");

    sleep(10);   // Zombie exists here

    wait(NULL);  // Solution
    printf("Zombie removed using wait()\n");

    return 0;
}
