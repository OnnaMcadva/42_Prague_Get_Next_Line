#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}

char	*ft_strchr(const char *s, int i)
{
	while (*s)
	{
		if (*s == (char)i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	join = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_get_line_from_left_str(char *left_str)
{
	int		i;
	char	*line;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		line[i] = left_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_update_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*new_left_str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	new_left_str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!new_left_str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		new_left_str[j++] = left_str[i++];
	new_left_str[j] = '\0';
	free(left_str);
	return (new_left_str);
}
