/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 11:34:13 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/29 13:58:04 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count_len;

	count_len = 0;
	while (s[count_len] != '\0')
		count_len++;
	return (count_len);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		size;
	size_t	i;

	i = 0;
	size = 0;
	while (src[size])
		++size;
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	r = (char *)s;
	while (*r)
	{
		if (*r == (char)c)
			return (r);
		r++;
	}
	if (*r == '\0' && c == '\0')
		return (r);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	char	*dest;
	char	*s_1;
	char	*s_2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	if (!(dest = (char *)malloc((total_len + 1) * sizeof(char))))
		return (0);
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		dest[i++] = *s_1++;
	while (*s_2)
		dest[i++] = *s_2++;
	dest[i] = '\0';
	return (dest);
}
