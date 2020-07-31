/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 04:59:01 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/03 11:58:55 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	length;

	length = 0;
	if (!dest)
		return (0);
	while (src[length])
		length++;
	if (!n)
		return (length);
	i = 0;
	while (i < n - 1 && *src)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
	return (length);
}
