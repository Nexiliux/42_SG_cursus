
/*functions needed: ft_strncpy, gnl_read_to_buffer, gnl_buffer_to_line*/

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	unsigned char	*s;
	int		i;

	i = nmemb * size;
	result = (void *)malloc(size * nmemb);
	if (!result)
		return (NULL);
	s = (unsigned char *) result;
	while (i)
	{
		*s++ = 0;
		i--;
	}
	return (result);
}

char	*ft_strdup(const char *s)
{
	int		clen;
	char	*result;
	int		i;

	i = 0;
	clen = 0;
	if (!s)
		return (ft_strdup(""));
	while (s[clen])
		clen++;
	result = malloc(sizeof(char) * (clen + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = malloc(sizeof(char) * (i + j + 1));
	if (!str)
		return (NULL);
	j = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	return (str);
}

void	ft_free(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

int	got_newline(char *storage)
{
	int	i;

	i = 0;
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}