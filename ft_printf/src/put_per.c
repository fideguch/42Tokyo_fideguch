/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_per.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:55:14 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/04 22:05:13 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info		*put_c(t_info *str, unsigned char c, int i)
{
	int		d;

	d = str->width - 1;
	if (i == 0)
	{
		if (str->flag[ZERO] == 1)
		{
			while (d--)
				ft_putchar_fd('0', 1);
		}
		else
		{
			while (d--)
				ft_putchar_fd(' ', 1);
		}
	}
	ft_putchar_fd(c, 1);
	if (i == 1)
		while (d--)
			ft_putchar_fd(' ', 1);
	str->len += str->width;
	return (str);
}

t_info				*put_per(t_info *str)
{
	unsigned char	c;

	c = '%';
	if (str->width > 1)
		str = put_c(str, c, str->flag[MINUS] == 1 ? 1 : 0);
	else
	{
		ft_putchar_fd(c, 1);
		str->len++;
	}
	str->string++;
	return (str);
}
