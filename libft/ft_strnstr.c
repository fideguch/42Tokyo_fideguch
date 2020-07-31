/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 18:38:44 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/13 20:37:15 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s, const char *find, size_t slen)
{
	size_t	find_l;
	size_t	s_l;
	char	*result;

	if (!*find)
		return ((char*)s);
	find_l = ft_strlen(find);
	s_l = ft_strlen(s);
	result = (char *)s;
	while (ft_strncmp(result, find, find_l) != 0)
	{
		result++;
		if (slen <= find_l || !(*result) || slen == 0)
			return (NULL);
		slen--;
	}
	if (slen < find_l)
		return (NULL);
	return (result);
}
