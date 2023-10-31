/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:20:08 by anmakaro          #+#    #+#             */
/*   Updated: 2023/10/31 10:45:38 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*saved_str[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_str[fd] = ft_read_and_append(fd, saved_str[fd]);
	if (!saved_str[fd])
		return (NULL);
	line = ft_getline_fromleftstr(saved_str[fd]);
	saved_str[fd] = ft_update_leftstr(saved_str[fd]);
	return (line);
}

/*
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    // Открываем файлы для чтения
    fd1 = open("tests/test1.txt", O_RDONLY);
    fd2 = open("tests/test2.txt", O_RDONLY);
    fd3 = open("tests/test3.txt", O_RDONLY);

    // Проверка открытия файлов
    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        perror("Error opening one of the files");
        return (1);
    }

    printf("Reading from test1.txt:\n");
    while ((line = get_next_line(fd1)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd1);
    printf("\n");

    printf("Reading from test2.txt:\n");
    while ((line = get_next_line(fd2)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd2);
    printf("\n");

    printf("Reading from test3.txt:\n");
    while ((line = get_next_line(fd3)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd3);
    printf("\n");

    return (0);
}
*/
