#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_get_line_from_left_str(char *left_str);
char	*ft_update_left_str(char *left_str);
char	*ft_read_and_append(int fd, char *buffer, char *saved_str);
char	*get_next_line(int fd);

#endif
