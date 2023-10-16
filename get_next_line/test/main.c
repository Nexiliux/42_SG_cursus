#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd1 = open ("test.txt", O_RDONLY);
	int	fd2 = open ("test2.txt", O_RDONLY);
	int	i = 2;
	while(i > 0)
	{
	printf ("fd1 output is: %s\n", get_next_line(fd1));
	printf("-------------------------------------------------------------------\n");
	printf ("fd2 output is: %s\n", get_next_line(fd2));
	i--;
	}
}
/*
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open ("test.txt", O_RDONLY);
	int	fd2 = open ("test2.txt", O_RDONLY);
	printf ("fd output is: %s\n", get_next_line(fd));
	printf("-------------------------------------------------------------------\n");
	printf ("fd2 output is: %s\n", get_next_line(fd2));
	printf("-------------------------------------------------------------------\n");
	printf ("fd output is: %s\n", get_next_line(fd));
	printf("-------------------------------------------------------------------\n");
	printf ("fd2 output is: %s\n", get_next_line(fd2));
}
*/