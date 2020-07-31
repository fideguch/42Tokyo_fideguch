/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 04:55:04 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/11 17:36:01 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*return_null(void)
{
	char	*r;

	if (!(r = (char *)ft_calloc(1, sizeof(char))))
		return (0);
	r[0] = '\0';
	return (r);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*dest;

	if (!s)
		return (NULL);
	if (len <= 0)
		return (return_null());
	if ((int)ft_strlen(s) <= (int)start)
		return (return_null());
	if (!(dest = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	i = -1;
	while (++i < len)
		dest[i] = s[start + i];
	dest[++i] = '\0';
	return (dest);
}
