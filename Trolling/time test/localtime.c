#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
// Set the TZ environment variable to Asia/Singapore
    setenv("TZ", "Asia/Singapore", 1);
    tzset(); // Update time zone information
    time_t current_time;
    struct tm *local_time_info;

    // Get the current time
    time(&current_time);

    // Convert the current time to the local time structure
    local_time_info = localtime(&current_time);

    // Display the information using printf
    printf("Current local time: %04d-%02d-%02d %02d:%02d:%02d\n",
           local_time_info->tm_year + 1900, // Year since 1900
           local_time_info->tm_mon + 1,     // Month (0-based)
           local_time_info->tm_mday,        // Day of the month
           local_time_info->tm_hour,        // Hour
           local_time_info->tm_min,         // Minute
           local_time_info->tm_sec          // Second
    );

    return 0;
}