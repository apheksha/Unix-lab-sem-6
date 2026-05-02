#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t c1, c2;
    int status;

    c1 = fork();
    if (c1 == 0) {
        printf("Child 1 PID: %d\n", getpid());
        sleep(2);
        exit(1);
    }

    c2 = fork();
    if (c2 == 0) {
        printf("Child 2 PID: %d\n", getpid());
        sleep(4);
        exit(2);
    }

    waitpid(c1, &status, 0);
    printf("waitpid collected child 1 (PID %d), status: %d\n",
           c1, WEXITSTATUS(status));

    wait(&status);
    printf("wait collected child 2, status: %d\n",
           WEXITSTATUS(status));

    return 0;
}
