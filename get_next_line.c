/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/24 18:49:01 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/01/31 19:42:54 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_remainder(char *remainder, char **line)
{
	char	*p_n;

	p_n = NULL;
	if (remainder)
	{
		p_n = ft_strchr(remainder, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(remainder);
			p_n++;
			while (*p_n)
			{
				*remainder = *p_n;
				p_n++;
			}
			*remainder = '\0';
		}
		*line = ft_strdup(remainder);
		while (*remainder)
		{
			*remainder = '\0';
			remainder++;
		}
	}
	else
		**line = '\0';
	return (p_n);
}

int	get_next_line(int fd, char **line) //1, 0 , -1
{
	char		buf[10 + 1];
	int			nbytesread;
	char		*p_n;
	static char	*remainder;
	char		*tmp;

	p_n = check_remainder(remainder, line);
	while (!p_n && (nbytesread = read(fd, buf, 10)))
	{
		buf[nbytesread] = '\0';
		p_n = ft_strchr(buf, '\n');
		if (p_n)
		{
			*p_n = '\0';
			p_n++;
			remainder = ft_strdup(p_n);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	if (nbytesread|| ft_strlen(remainder) || ft_strlen(*line))
		return (1);
	else
		return (0);
}

int	main(void)
{
	char	*line;
	int		fd;

	fd = open("easter_lyrics.txt", O_RDONLY);
	get_next_line(fd, &line);
	//printf("%s\n", line);
}
 