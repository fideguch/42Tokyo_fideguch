/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 03:35:53 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/03 11:40:29 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	const char		*s;

	i = 0;
	d = dest;
	s = src;
	while (i < n)
	{
		if (*(unsigned char*)s == (unsigned char)c)
		{
			*d = *s;
			d++;
			return (d);
		}
		*d = *s;
		i++;
		d++;
		s++;
	}
	return (0);
}
