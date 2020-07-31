/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:59:26 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/04 11:07:42 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	char	*dest;
	char	*s_1;
	char	*s_2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	if (!(dest = (char *)ft_calloc(total_len + 1, sizeof(char))))
		return (0);
	s_1 = (char *)s1;
	s_2 = (char *)s2;
	while (*s_1)
		dest[i++] = *s_1++;
	while (*s_2)
		dest[i++] = *s_2++;
	dest[i] = '\0';
	return (dest);
}
