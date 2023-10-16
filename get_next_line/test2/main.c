#include <stdio.h>

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (*str)
        i++;
    return (i);
}

int     main()
{
        char *str = "";
        printf("%d", ft_strlen(str));
        return(0);
}