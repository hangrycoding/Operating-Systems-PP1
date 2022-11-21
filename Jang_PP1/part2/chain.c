// Junwoo Jang - CS4352 Project1

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



// Main:Fork. All parents can have one child only(Chain processes)
int main(int argc, char* argv[])
{
    //  Allow only two arguments(program_name, number of processes(integer))
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <Num_Of_Processes>\n", argv[0]); // To make sure no errors, flush output
        return 1; // Error
    }

    int processes_amount = atoi(argv[1]);

    // Repeat within [0, processes_amount)
    for (int i = 0; i < processes_amount; i++) {
        pid_t pid = fork();

        if (pid == -1) {
            fprintf(stderr, "Cannot create child process number %d\n", i);
            return 1; // Error
        } else if (pid == 0) {
            // Display the child process
            printf("Hello from process %d\n", getpid());
            // To make sure no errors, flush output
            if (fflush(stdout) != 0) {
                fprintf(stderr, "Cannot flush output to stdout.");
                return 1; // Error
            }
        } else {
            wait(NULL); // Wait for its own child processes
            return 0; 
        }
    }
  
    return 0;
}
