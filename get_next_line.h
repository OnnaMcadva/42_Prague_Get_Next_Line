/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:19:28 by anmakaro          #+#    #+#             */
/*   Updated: 2023/10/30 14:39:42 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen_v(char *s);
char	*ft_strchr_v(char *s, int c);
char	*ft_strjoin_v(char *left_str, char *buff);
char	*ft_getline_fromleftstr(char *left_str);
char	*ft_update_leftstr(char *left_str);
char	*ft_read_and_append(int fd, char *saved_str);
char	*get_next_line(int fd);

#endif
