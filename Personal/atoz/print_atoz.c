#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/*
This program takes in one(1) argument after ./a.out and will display each character in tandem
until the displayed character matches the character in the same position within the argument
string. 
Once it matches, it will move onto the next position and will start from 'a' onwards.
The order is displayed cyclically as follows: a-z, A-Z, 0-9, all other symbols.
There is a delay added in for flair, this is done using usleep.
*/

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
		if (str[i] == 9)
                        buffer[i] = 9;
		if (str[i] == 11)
                        buffer[i] = 11;
                while(buffer[i] != str[i])
                {
                        printf("%s\n", buffer);
			/*
			if (buffer[i] == 'z') //lower to uppercase
				buffer[i] = 'A';
			else if (buffer[i] == 'Z') //uppercase to numericals
				buffer[i] = '0';
			else if (buffer[i] == '9') //numericals to symbols
				buffer[i] = '!';
			else if (buffer[i] == '/') //symbol jump
				buffer[i] = ':';
			else if (buffer[i] == '@') //symbol jump
				buffer[i] = '[';
			else if (buffer[i] == '`') //symbol jump
				buffer[i] = '{';
			else if (buffer[i] == '~') //back to a
				buffer[i] = 'a';
			else
				buffer[i]++;
			*/
			if (buffer[i] == 'z') buffer[i] = 'A'; //CGPT way, didn't know this was a thing but damn
			else if (buffer[i] == 'Z') buffer[i] = '0';
			else if (buffer[i] == '9') buffer[i] = '!';
			else if (buffer[i] == '/') buffer[i] = ':';
			else if (buffer[i] == '@') buffer[i] = '[';
			else if (buffer[i] == '`') buffer[i] = '{';
			else if (buffer[i] == '~') buffer[i] = 'a';
			else buffer[i]++;
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