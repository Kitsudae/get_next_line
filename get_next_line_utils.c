/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kvodorez <kvodorez@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/01/25 16:54:14 by kvodorez      #+#    #+#                 */
/*   Updated: 2022/01/31 19:32:08 by kvodorez      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i ++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len_s;

	c = (const char)c;
	len_s = ft_strlen(s);
	i = 0;
	if (c == 0)
		return ((char *)&s[len_s]);
	while (i < len_s)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	size;
// 	char	*s_concat;

// 	if (!s1)
// 		return (ft_strdup(s2));
// 	size = ft_strlen(s1) + ft_strlen(s2) + 1;
// 	s_concat = (char *)malloc(size);
// 	if (!s_concat)
// 		return (NULL);
// 	ft_strlcat(s_concat, s1, ft_strlen(s1));
// 	ft_strlcat(s_concat, s2, ft_strlen(s2));
// 	return ((char *)s1);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	i;
	unsigned int	j;
	char			*out_str;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = -1;
	out_str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!out_str)
		return (NULL);
	while (s1[i])
	{
		out_str[i] = s1[i];
		i++;
	}
	while (s2[++j])
		out_str[i++] = s2[j];
	out_str[i] = '\0';
	return (out_str);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;
	size_t	len_dst;

	len_src = ft_strlen(src);
	i = 0;
	while (dst[i] && (i < dstsize))
		i++;
	len_dst = i;
	if (len_dst >= dstsize)
		return (len_src + dstsize);
	if (dstsize > 0 && dst != 0)
	{
		j = 0;
		while (src[j] != 0 && j < dstsize - 1 - len_dst)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	return (len_src + len_dst);
}
