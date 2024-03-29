#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

// Signal handler for confirmation from server
void confirmation_handler(int sig) {
    if (sig == SIGUSR1) {
        printf("String received by server.\n");
    } else {
        printf("Error: String not received by server.\n");
    }
    exit(0);
}

int main(int argc, char *argv[]) {
    // Check if correct number of arguments provided
    if (argc != 3) {
        printf("Usage: %s [server_pid] [message]\n", argv[0]);
        exit(1);
    }
    
    // Extract server PID from command-line arguments
    pid_t server_pid = atoi(argv[1]);
    // Extract message from command-line arguments
    char *message = argv[2];
    
    // Set signal handler for confirmation from server
    signal(SIGUSR1, confirmation_handler);
    
    // Send each character of the message to the server
    for (int i = 0; message[i] != '\0'; i++) {
        // Get the current character
        char current_char = message[i];
        // Send each bit of the current character to the server
        for (int j = 0; j < 8; j++) {
            if (current_char & (1 << j)) {
                kill(server_pid, SIGUSR2);
            } else {
                kill(server_pid, SIGUSR1);
            }
            // Sleep to ensure correct timing between bits
            usleep(100);
        }
    }
    
    // Signal the end of the message to the server
    for (int i = 0; i < 8; i++) {
        kill(server_pid, SIGUSR1);
        usleep(100);
    }
    
    // Wait for confirmation from the server
    while (1) {
        sleep(1);
    }
    
    return 0;
}
