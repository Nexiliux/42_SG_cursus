#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <string.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char    *store_remainder(char *storage);
char    *ft_line(char *storage, char *line);
void    get_str(char **storage, char *buffer, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free(char **s1, char **s2, char **s3);
int	got_newline(char *storage);
int     ft_strlen(char *str);

#endif