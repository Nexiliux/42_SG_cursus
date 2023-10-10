#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd = open ("test.txt", O_RDONLY);
	printf ("output is: %s", get_next_line(fd));
	printf ("output is: %s", get_next_line(fd));
	printf ("output is: %s", get_next_line(fd));
	printf ("output is: %s", get_next_line(fd));
}