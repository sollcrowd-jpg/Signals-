#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

// Global variables to track time and alarms
int alarm_count = 0;
int running_time = 0;

// Signal handler for SIGALRM (triggered by the alarm every second)
void alarm_handler(int signum) {
    alarm_count++;
    running_time++;
    printf("Hello World!\n");
    alarm(1);  // Reschedule the alarm for another second
}

// Signal handler for SIGINT (triggered when CTRL-C is pressed)
void sigint_handler(int signum) {
    printf("\nSIGINT received (CTRL-C pressed)\n");
    printf("Program ran for %d seconds, and %d alarms were delivered.\n", running_time, alarm_count);
    exit(0);  // Exit the program
}

int main() {
    // Set up the signal handler for SIGALRM
    signal(SIGALRM, alarm_handler);

    // Set up the signal handler for SIGINT (CTRL-C)
    signal(SIGINT, sigint_handler);

    // Set an alarm to go off in 1 second
    alarm(1);

    // Infinite loop waiting for signals
    while (1) {
        pause();  // Wait for signals (SIGALRM or SIGINT)
    }

    return 0;
}
