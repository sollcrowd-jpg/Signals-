#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Global variable to indicate the signal has been handled
int signal_handled = 0;

// Signal handler for SIGALRM
void handler(int signum) {
    printf("Hello World!\n");
    signal_handled = 1;  // Set the flag to indicate the handler was invoked
}

int main() {
    // Set up the signal handler for SIGALRM
    signal(SIGALRM, handler);

    // Set an alarm to go off in 1 second
    alarm(1);

    // Busy wait loop until the signal is received and handled
    while (!signal_handled) {
        // Do nothing, waiting for the signal
    }

    // Print the message after the signal handler is invoked
    printf("Turing was right!\n");

    return 0;
}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// Global variable to track the signal
int signal_handled = 0;

// Signal handler for SIGALRM
void handler(int signum) {
    printf("Hello World!\n");
    signal_handled = 1;  // Set the flag to indicate the handler was invoked
    alarm(1);  // Reschedule the alarm to go off after 1 second
}

int main() {
    // Set up the signal handler for SIGALRM
    signal(SIGALRM, handler);

    // Set an alarm to go off in 1 second
    alarm(1);

    // Infinite loop
    while (1) {
        if (signal_handled) {
            printf("Turing was right!\n");
            signal_handled = 0;  // Reset the flag
        }
    }

    return 0;
}
