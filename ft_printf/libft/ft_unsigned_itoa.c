/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:18:03 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 05:11:52 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*cast_char(char *r, unsigned int n)
{
	char	tmp;
	int		i;
	int		a;

	i = 0;
	while (n > 0)
	{
		r[i] = n % 10 + '0';
		i++;
		n /= 10;
	}
	a = 0;
	while (a < i / 2)
	{
		tmp = r[a];
		r[a] = r[i - a - 1];
		r[i - a - 1] = tmp;
		a++;
	}
	return (r);
}

static int	memory_size(unsigned int n, unsigned int size)
{
	if (n < 10)
		return (1);
	if (n >= 10)
		size = memory_size(n / 10, size + 1);
	return (size + 1);
}

static char	*return_min(void)
{
	char	*r;

	if (!(r = (char *)ft_calloc(2, sizeof(char))))
		return (0);
	r[0] = '0';
	return (r);
}

char		*ft_unsigned_itoa(unsigned int n)
{
	unsigned int		size;
	char				*result;

	if (n == 0)
		return (return_min());
	size = memory_size(n, 0);
	if (!(result = (char *)ft_calloc(size + 1, sizeof(char))))
		return (0);
	return (cast_char(result, n));
}
