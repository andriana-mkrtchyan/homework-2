#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {
    pid_t pid = fork();
    if (pid < 0) { 
	    perror("fork"); 
	    return 1; 
    }

    if (pid == 0) {
        execl("/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        if (errno == ENOENT)
            execl("/usr/bin/grep", "grep", "main", "test.txt", (char *)NULL);
        perror("execl grep");
        _exit(127);
    }

    if (waitpid(pid, NULL, 0) < 0) { 
	    perror("waitpid"); 
	    return 1; 
    }
    puts("Parent process completed");
    return 0;
}

