#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    if (fork() < 0) {
	    perror("fork1"); 
	    exit(1);
    }
    if (fork() < 0) { 
	    perror("fork2"); 
	    exit(1);
    }
    if (fork() < 0) { 
	    perror("fork3"); 
	    exit(1);
    } 
    if (fork() < 0) { 
	    perror("fork4"); 
	    exit(1); 
    }

    printf("pid=%ld ppid=%ld\n", (long)getpid(), (long)getppid());
    while (wait(NULL) > 0) {}
    return 0;
}

