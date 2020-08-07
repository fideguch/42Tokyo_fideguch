/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 03:22:41 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 05:13:51 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info		*put_c(t_info *str, unsigned char c, int i)
{
	int		d;

	d = str->width - 1;
	if (i == 0)
		while (d--)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(c, 1);
	if (i == 1)
		while (d--)
			ft_putchar_fd(' ', 1);
	str->len += str->width;
	return (str);
}

t_info				*put_char(t_info *str)
{
	unsigned char	c;

	c = va_arg(str->list, int);
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
