/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 03:01:37 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/03 11:38:42 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		*d = *s;
		i++;
		d++;
		s++;
	}
	return (dest);
}
