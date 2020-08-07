/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 06:17:38 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 17:33:43 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		put_h(int p)
{
	if (p < 10)
		return (p + '0');
	if (p >= 10)
		return ((p - 10) + 'a');
	return (0);
}

void			ft_puthex(unsigned long long num, int plen, int d)
{
	char	r[plen == 0 ? 1 : plen + 1];

	if ((int)num == 0 && (int)plen == 1 && d == 1)
	{
		ft_putchar_fd('0', 1);
		return ;
	}
	if ((int)num == 0 && (int)plen == 0 && d == 0)
		return ;
	r[plen] = '\0';
	while (num && plen)
	{
		r[--plen] = put_h(num % 16);
		num /= 16;
	}
	ft_putstr_fd(r, 1);
	return ;
}
