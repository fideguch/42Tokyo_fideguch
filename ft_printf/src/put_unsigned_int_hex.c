/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:33:53 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 17:51:49 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char		put_h(int p, char a)
{
	if (p < 10)
		return (p + '0');
	if (p >= 10)
	{
		if (a == 'X')
			return ((p - 10) + 'A');
		return ((p - 10) + 'a');
	}
	return (0);
}

char			*casthex(unsigned int num, int plen, char a)
{
	char	*r;
	int		tmp;

	r = (char *)ft_calloc(plen + 1, sizeof(char));
	tmp = plen;
	while (num && plen)
	{
		r[--plen] = put_h(num % 16, a);
		num /= 16;
	}
	if (tmp == 0)
		r[0] = '0';
	return (r);
}

static t_info	*process_tmp(t_info *str, char *str_tmp)
{
	if (str->width > (int)ft_strlen(str_tmp))
	{
		if (str->flag[MINUS] == 1)
			str = put_result_mina(str, str->width, str_tmp);
		else if (str->flag[ZERO] == 1 && str->flag[POINT] == 0)
			str = put_result(str, str_tmp, '0', 0);
		else
			str = put_result(str, str_tmp, ' ', 0);
	}
	else
		ft_putstr_fd(str_tmp, 1);
	return (str);
}

t_info			*put_unsigned_int_hex(t_info *str)
{
	unsigned int	ptr;
	unsigned int	tmp;
	char			*s;
	char			*str_tmp;
	int				p_len;

	if (str->flag[POINT] == 1)
		str->flag[ZERO] = 0;
	tmp = va_arg(str->list, unsigned int);
	ptr = tmp;
	p_len = 2;
	while (tmp > 0)
	{
		p_len++;
		tmp /= 16;
	}
	s = casthex(ptr, p_len - 2, *str->string);
	str_tmp = precision_tmp(str->precision, s, 0, str->p_default);
	str = process_tmp(str, str_tmp);
	str->len += ft_strlen(str_tmp);
	str->string++;
	if (!(str->precision == 0 && *str_tmp == '\0' && str->p_default == 0))
		free(str_tmp);
	free(s);
	return (str);
}
