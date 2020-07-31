/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 04:32:24 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/14 08:48:52 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(const char *str, char c)
{
	int		cnt;
	char	*s;

	s = (char *)str;
	cnt = 1;
	++s;
	while (*s)
	{
		if (*s == c && *(s - 1) != c)
			++cnt;
		++s;
	}
	if (*(s - 1) != c)
		cnt++;
	return (cnt);
}

static char	*get_memory(char *str, char c)
{
	int		i;

	i = 0;
	while (*str && (*str != c))
		++str;
	return (str);
}

static char	**check_str(const char *s, char c)
{
	char	**r;

	if (!s || !(r = (char**)ft_calloc(get_len(s, c), sizeof(char*))))
		return (NULL);
	return (r);
}

static char	**free_all(char **r, int i)
{
	int		a;

	a = 0;
	while (a <= i)
		free(r[a++]);
	free(r);
	return (0);
}

char		**ft_split(char const *s, char c)
{
	char	**r;
	int		i;
	char	*str;
	char	*from;

	if (!(r = check_str(s, c)))
		return (0);
	str = (char *)s;
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			from = str;
			str = get_memory(str, c);
			if (!(r[i] = (char *)ft_calloc(str - from + 1, sizeof(char))))
				return (free_all(r, i));
			ft_strlcpy(r[i++], from, str - from + 1);
			if (*str == 0)
				break ;
		}
		str++;
	}
	return (r);
}
