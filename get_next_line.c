/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:37 by anmakaro          #+#    #+#             */
/*   Updated: 2023/10/30 15:24:38 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_append(int fd, char *saved_str)
{
	char	*temp;
	int		bytes_read;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_v(saved_str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[bytes_read] = '\0';
		saved_str = ft_strjoin_v(saved_str, temp);
	}
	free(temp);
	return (saved_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*saved_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str = ft_read_and_append(fd, saved_str);
	if (!saved_str)
		return (NULL);
	line = ft_getline_fromleftstr(saved_str);
	saved_str = ft_update_leftstr(saved_str);
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	int		line_num;
	int		fd1;
	//int		fd2;
	//int		fd3;

	fd1 = open("tests/test1.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	//fd3 = open("tests/test3.txt", O_RDONLY);

	line_num = 1;
	while (line_num < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d] from fd1: %s\n", line_num, line);
		free(line);

		//line = get_next_line(fd2);
		//printf("line [%02d] from fd2: %s\n", line_num, line);
		//free(line);

		//line = get_next_line(fd3);
		//printf("line [%02d] from fd3: %s\n", line_num, line);
		//free(line);

		line_num++;
	}

	close(fd1);
	//close(fd2);
	//close(fd3);

	return (0);
}
*/
