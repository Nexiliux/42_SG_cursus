#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
/*
int	main()
{
	int	fd1 = open ("test.txt", O_RDONLY);
	int	fd2 = open ("test2.txt", O_RDONLY);
	int	i = 5;
	while(i > 0)
	{
	printf ("fd1 output is: %s\n", get_next_line(fd1));
	printf ("fd2 output is: %s\n", get_next_line(fd2));
	printf("-------------------------------------------------------------------\n");
	i--;
	}
}
*/
int	main()
{
	int	fd1 = open ("test.txt", O_RDONLY);
	int	fd2 = open ("test2.txt", O_RDONLY);
	int	i = 2;
	while(--i + 1> 0)
	{
		printf ("%s\n", get_next_line(fd1));
		printf ("%s\n", get_next_line(fd2));
	}
}