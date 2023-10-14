#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    struct tm *time_info;
    char time_string[25]; // To store the formatted time

    // Get the current time
    time(&current_time);

    // Convert the current time to the local time structure
    time_info = localtime(&current_time);

    // Format the time as a string in the desired format
    strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);

    // Print the formatted time
    printf("Current time and date: %s\n", time_string);

    return 0;
}
