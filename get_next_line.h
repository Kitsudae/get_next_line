/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/27 18:40:50 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/03/09 17:06:18 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# define BUFFER_SIZE  1

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*read_full_line(int fd, char *saved_line, char *buff);
char	*get_remainder(char *saved_line);
char	*trim_line(char *saved_line);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *dst, char *src);

#endif