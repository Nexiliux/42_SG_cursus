#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void delay(int milliseconds) {
    usleep(milliseconds * 1000); // Convert milliseconds to microseconds
}

void    atoz(int argc, char **string)
{
        int     i = 0;
        int     size = 1;
        if (argc <= 1)
        {
                printf("bro add arguments");
                return ;
        }
        char    *str = strdup(string[1]);
        char    *buffer = calloc(size, 1);
        printf("code starts\n");
        
        while (str[i])
        {
                buffer[i] = 'a';
                if (str[i] == ' ')
                        buffer[i] = ' ';
                while(buffer[i] != str[i])
                {
                        printf("%s\n", buffer);
                        buffer[i]++;
                        delay(25);
                }
                printf("%s\n", buffer);
                delay(25);
                if (str[i])
                {
                        char *temp = strdup(buffer);
                        size++;
                        buffer = calloc(size, 1);
                        buffer = strncpy(buffer, temp, size - 1);
                        free(temp);
                }
                i++;
        }
}

int     main(int argc, char *argv[])
{
        atoz(argc, argv);
}