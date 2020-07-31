/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 02:21:55 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/03 12:23:45 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)buf1;
	s = (unsigned char *)buf2;
	if (n > 0)
	{
		while (n-- > 0)
		{
			if (*d - *s != 0)
				return (*d - *s);
			d++;
			s++;
		}
	}
	return (0);
}
