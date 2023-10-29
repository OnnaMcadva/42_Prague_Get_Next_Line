
#include "get_next_line.h"

char	*ft_read_and_append(int fd, char *buffer, char *saved_str)
{
	char	*temp;
	int		bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	temp = ft_strjoin(saved_str, buffer);
	free(saved_str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved_str;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);

	saved_str = ft_read_and_append(fd, buffer, saved_str);
	if (!saved_str)
		return (NULL);

	line = ft_get_line_from_left_str(saved_str);
	saved_str = ft_update_left_str(saved_str);
	return (line);
}


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		line_num;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test1.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);

	line_num = 1;
	while (line_num < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d] from fd1: %s\n", line_num, line);
		free(line);

		line = get_next_line(fd2);
		printf("line [%02d] from fd2: %s\n", line_num, line);
		free(line);

		line = get_next_line(fd3);
		printf("line [%02d] from fd3: %s\n", line_num, line);
		free(line);

		line_num++;
	}

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
