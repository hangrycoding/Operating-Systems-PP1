// Junwoo Jang - CS4352 Project1

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>



// Main:Fork. It uses "one" parent & "multiple" child processes.
int main(int argc, char* argv[])
{
    // Allow only two arguments (program_name & the number of processes(integer))
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
        } else if (pid == 0) { // Exit the process If it is in the child process
            
            printf("Hello from process %d\n", getpid());
            // To make sure no errors, flush output
            if (fflush(stdout) != 0) {
                fprintf(stderr, "Cannot flush output to stdout.");
                return 1; // Error
            }
            return 0;
        }
    }
  
    for (int i = 0; i < processes_amount; i++) //for loop: it will run when it is parent process only
       
        wait(NULL);
  
    return 0;
}
