#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_strncpy(char* dest, const char* src, size_t n);
ssize_t	gnl_read_into_buffer(int fd, char* buffer, size_t buffer_size);
char	*gnl_buffer_to_line(char* line, int lineLen, char* buffer, ssize_t* bytesRead);

#endif