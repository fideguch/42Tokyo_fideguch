/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 02:38:34 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/11 13:29:41 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = dest;
	i = 0;
	while (i < len)
	{
		*ptr = (unsigned char)val;
		i++;
		ptr++;
	}
	return (dest);
}
