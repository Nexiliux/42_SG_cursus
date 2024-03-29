#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Global variable to store received characters
char received_char = 0;

// Signal handler for receiving bits from clients
void sig_handler(int sig) {
    static int bit_count = 0;
    static char current_char = 0;
    
    // Shift the current character to the left
    current_char <<= 1;
    
    // Check if the received signal is SIGUSR2
    if (sig == SIGUSR2) {
        current_char |= 1;
    }
    
    // Increment bit count
    bit_count++;
    
    // If 8 bits received, print the character and reset variables
    if (bit_count == 8) {
        printf("%c", current_char);
        fflush(stdout);
        bit_count = 0;
        current_char = 0;
    }
}

int main() {
    // Print server PID
    printf("Server PID: %d\n", getpid());
    
    // Set signal handler for SIGUSR1 and SIGUSR2
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    // Infinite loop to keep the server running
    while (1) {
        // Sleep to prevent CPU hogging
        sleep(1);
    }
    
    return 0;
}
