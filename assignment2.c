#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t c1 = fork();
    if (c1 < 0) { 
	    perror("fork c1"); 
	    return 1;
    }
    if (c1 == 0) {         
        execlp("ls", "ls", (char*)NULL);
        perror("execlp ls");
        _exit(127);
    }
    if (waitpid(c1, NULL, 0) < 0) { 
	    perror("waitpid c1"); 
	    return 1; 
    }

    pid_t c2 = fork();
    if (c2 < 0) { 
	    perror("fork c2"); 
	    return 1; 
    }
    if (c2 == 0) {                
        execlp("date", "date", (char*)NULL);
        perror("execlp date");
        _exit(127);
    }
    if (waitpid(c2, NULL, 0) < 0) { 
	    perror("waitpid c2"); 
	    return 1; 
    }

    puts("Parent process done");
    return 0;
}

