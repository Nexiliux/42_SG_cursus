#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Convert milliseconds to microseconds
}

int main()
{
   printf("Wait for 5 seconds to exit.\n");
   delay(1000);
   return 0;
}