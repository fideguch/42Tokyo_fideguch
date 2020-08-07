/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/02 16:43:06 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/07 01:05:41 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*deelmin(int p)
{
	char	*s;
	int		i;
	int		a;

	i = 0;
	a = p - MIN_LEN + 1;
	s = (char *)ft_calloc(a > 0 ? p + 1 : MIN_LEN + 1, sizeof(char));
	s[i++] = '-';
	if (a > 0)
		while (a--)
			s[i++] = '0';
	ft_strlcpy(s + i, "2147483648", MIN_LEN);
	return (s);
}

static char	*deelstr(int tmp, t_info *str, int m)
{
	char	*ss;
	char	*s;

	if (tmp == INT_MIN)
		return (deelmin(str->precision));
	ss = ft_itoa(tmp < 0 ? -tmp : tmp);
	s = precision_tmp(str->precision, ss, m, str->p_default);
	free(ss);
	return (s);
}

t_info		*put_int(t_info *str)
{
	int		tmp;
	int		m;
	char	*str_tmp;

	str->flag[ZERO] = str->flag[POINT] == 1 ? 0 : str->flag[ZERO];
	tmp = va_arg(str->list, int);
	m = tmp < 0 ? 1 : 0;
	str_tmp = deelstr(tmp, str, m);
	if (str->width > (int)ft_strlen(str_tmp))
	{
		if (str->flag[MINUS] == 1)
			str = put_result_mina(str, str->width, str_tmp);
		else if (str->flag[ZERO] == 1 && str->flag[POINT] == 0)
			str = put_result(str, str_tmp, '0', m);
		else
			str = put_result(str, str_tmp, ' ', 0);
	}
	else
		ft_putstr_fd(str_tmp, 1);
	str->len += ft_strlen(str_tmp);
	str->string++;
	if (!(str->precision == 0 && *str_tmp == '\0' && str->p_default == 0))
		free(str_tmp);
	return (str);
}
