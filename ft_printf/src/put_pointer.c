/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 05:07:32 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 05:41:51 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info		*put_p(t_info *str, unsigned long long ptr, int i, int l)
{
	int		d;
	int		p;

	p = str->precision;
	d = str->width - (l + 2);
	if (i == 0)
		while (d--)
			ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	if ((p = p - l) > 0)
		while (p--)
			ft_putchar_fd('0', 1);
	ft_puthex(ptr, l, str->p_default);
	if (i == 1)
		while (d--)
			ft_putchar_fd(' ', 1);
	p = str->precision;
	str->len += p + l + 2 > str->width ? p + l + 2 : str->width;
	return (str);
}

static int			get_ptr_len(unsigned long long tmp, int len)
{
	while (tmp > 0)
	{
		len++;
		tmp /= 16;
	}
	return (len);
}

t_info				*put_pointer(t_info *str)
{
	unsigned long long	ptr;
	int					ptr_len;
	int					p;

	p = str->precision;
	ptr = (unsigned long long)va_arg(str->list, void *);
	ptr_len = ptr == 0 && str->p_default == 1 ? 3 : 2;
	ptr_len = get_ptr_len(ptr, ptr_len);
	if (str->width > ptr_len)
		str = put_p(str, ptr, str->flag[MINUS] == 1 ? 1 : 0, ptr_len - 2);
	else
	{
		ft_putstr_fd("0x", 1);
		if ((p = p - (ptr_len - 2)) > 0)
			while (p--)
				ft_putchar_fd('0', 1);
		ft_puthex(ptr, ptr_len - 2, str->p_default);
		str->len += str->precision + 2 > ptr_len ? str->precision + 2 : ptr_len;
	}
	str->string++;
	return (str);
}
