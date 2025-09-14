#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { 
	    perror("fork"); 
	    return 1; 
    }

    if (pid == 0) {
        execl("/bin/echo", "echo", "Hello from the child process", (char *)NULL);
        perror("execl echo");
        _exit(127);
    }

    if (waitpid(pid, NULL, 0) < 0) { 
	    perror("waitpid"); 
	    return 1; 
    }
    puts("Parent process done");
    return 0;
}

