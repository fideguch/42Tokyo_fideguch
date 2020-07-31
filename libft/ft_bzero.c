/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/26 02:35:30 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/03 10:47:34 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = str;
	i = 0;
	while (i < n)
	{
		*dest = '\0';
		i++;
		dest++;
	}
	return (str);
}
