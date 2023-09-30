
/*functions needed: ft_strncpy, gnl_read_to_buffer, gnl_buffer_to_line*/

#include "get_next_line.h"

char    *ft_strncpy(char* dest, const char* src, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        if (src[i] == '\0') 
        {
            while (i < n)
                dest[i++] = '\0';
        }
        else
        {
            dest[i] = src[i];
            i++;
        }
    }
    return dest;
}

// Use the read() function to read data from the file descriptor into the buffer
// Handle errors and return the number of bytes read
ssize_t gnl_read_into_buffer(int fd, char* buffer, size_t buffer_size)
{
    ssize_t bytesRead;

    bytesRead = read(fd, buffer, buffer_size);
    if (bytesRead == -1)
        return (-1);
    return (bytesRead);
}

// Helper function to allocate and copy a line from the buffer
// Returns a dynamically allocated string containing the line
char    *gnl_buffer_to_line(char *line, int lineLen, char *buffer, ssize_t *bytesRead)
{
    char* temp;
    
    temp = (char*)malloc(lineLen + 1)
    if (!temp)
            return (NULL);
    if (line)
    {
        ft_strncpy(temp, line, lineLen);
        free(line);
    }
    ft_strncpy(temp + lineLen, buffer, lineLen + 1);
    *bytesRead -= lineLen;
    lineLen = 0;
    return (temp);
}