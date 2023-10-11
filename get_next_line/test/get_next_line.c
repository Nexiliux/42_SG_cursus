
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 3
#endif
#include "get_next_line.h"
#include <stdio.h>

char    *store_remainder(char *storage)
{
    char    *buffer;
    int     i;
    int     k;
    printf("STORE_REMAINDER STARTS\n");
    i = 0;
    k = 0;
    while (storage[i] && storage[i] != '\n')
        i++;
    if (storage[i] == '\n')
        i++;
    while (storage[k])
        k++;
    buffer = ft_calloc(k - i + 1, 1);
    if (!buffer)
        return (NULL);
    k = 0;
    while (storage[i + k])
    {
        buffer[k] = storage[i + k];
        k++;
    }
    printf("buffer is: %s\n", buffer);
    printf("STORE_REMAINDER ENDS\n");
    return (buffer);
}

char    *ft_line(char *storage)
{
    char    *buffer;
    int     i;
    int     k;
    printf("FTLINE STARTS\n");
    i = 0;
    k = 0;
    while (storage[i] && storage[i] != '\n')
        i++;
    if (storage[i] == '\n')
        i++;
    buffer = ft_calloc(i + 1, 1);
    if (!buffer)
        return (NULL);
    while (k < i)
    {
        buffer[k] = storage[k];
        k++;
    }
    buffer[k] = '\0';
    printf("buffer is: %s\n", buffer);
    printf("FTLINE ENDS\n");
    return (buffer);
}

void    get_str(char **storage, char *buffer, int fd)
{
    int     size;
    char    *temp;

    printf("GET_STR STARTS\n");
    temp = ft_calloc(BUFFER_SIZE + 1, 1);
    if (!temp)
        return ;
    size = 1;
    while (size > 0)
    {
        size = read(fd, temp, BUFFER_SIZE);
        if (size == -1)
        {
            ft_free(storage, &buffer, &temp);
            return ;
        }
        printf("size is: %d\n", size);
        temp[size] = '\0';
        printf("temp is: %s\n", temp);
        buffer = ft_strdup(*storage);
        printf("buffer is: %s\n", buffer);
        ft_free(storage, 0, 0);
        printf("storage after ft_free is: %s\n", *storage);
        *storage = ft_strjoin(buffer, temp);
        printf("storage after ft_strjoin is: %s\n", *storage);
        ft_free(&buffer, 0, 0);
        if(got_newline(*storage))
            break;
    }
    ft_free(&temp, 0, 0);
    printf("temp is: %s\n", temp);
    printf("buffer is: %s\n", buffer);
    printf("END OF GETSTR\n");
}

char    *get_next_line(int fd)
{
    static char *storage[1024];
    char    *buffer;
    char    *line;
    printf("GET_NEXT_LINE STARTS\n");
    buffer = NULL;
    if (fd <= 0 || fd > 1024 || BUFFER_SIZE <= 0)
        return (NULL);
    printf("fd is: %d\n", fd);
    printf("buffer is: %s\n", buffer);
    printf("storage[fd] is: %s\n", storage[fd]);
    get_str(&storage[fd], buffer, fd);
    printf("AFTER GETSTR\n");
    printf("buffer is: %s\n", buffer);
    printf("storage is: %s\n", storage[fd]);
    if (storage[fd])
    {
        line = ft_line(storage[fd]);
        printf("line is: %s\n", line);
        buffer = store_remainder(storage[fd]);
        printf("buffer is: %s\n", buffer);
        ft_free(&storage[fd], 0, 0);
        printf("after free storage[fd]: %s\n", storage[fd]);
        storage[fd] = ft_strdup(buffer);
        if (*storage[fd] == '\0')
            ft_free(&storage[fd], 0, 0);
        printf("after storage[fd] = buffer, storage[fd] is: %s\n", storage[fd]);
        ft_free(&buffer, 0, 0);
    }
    printf("GET_NEXT_LINE ENDS\n");
    printf("check memories:\nBUFFER: %s\nSTORAGE[fd]: %s\nLINE: %s\n", buffer, storage[fd], line);
    return (line);
}