/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 23:58:36 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/13 20:53:01 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_in(char c, const char *set, int set_len)
{
	int		i;

	i = 0;
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int		result_len(char *s, const char *set, int set_len)
{
	int		i;
	int		result;
	char	*s_1;

	i = 0;
	result = (int)ft_strlen(s);
	s_1 = (char *)s;
	while (s_1[i])
	{
		if (!(set_in(s_1[i++], set, set_len)))
			break ;
	}
	result -= i - 1;
	if (result <= 0)
		return (0);
	i = (int)ft_strlen(s) - 1;
	while (s_1[i])
	{
		if (!(set_in(s_1[i--], set, set_len)))
			break ;
	}
	result -= (int)ft_strlen(s) - i - 2;
	return (result);
}

static char		*return_null(void)
{
	char	*r;

	if (!(r = (char *)ft_calloc(1, sizeof(char))))
		return (0);
	r[0] = '\0';
	return (r);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		n;
	int		i;
	int		len;
	char	*s_1;
	char	*result;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	n = 0;
	i = 0;
	len = (int)ft_strlen(set);
	s_1 = (char *)s1;
	if (result_len(s_1, set, len) <= 0)
		return (return_null());
	if (!(result = (char *)ft_calloc(result_len(s_1, set, len) + 1\
	, sizeof(char))))
		return (0);
	while ((set_in(s_1[n], set, len)))
		n++;
	while (i < result_len(s_1, set, len))
		result[i++] = s_1[n++];
	result[i] = '\0';
	return (result);
}
