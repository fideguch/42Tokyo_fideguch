/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 04:22:24 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 18:50:31 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static t_info		*put_s(t_info *str, char *s, char c, int less_width)
{
	int		d;

	if (less_width == 1)
	{
		d = str->width - ft_strlen(s);
		if (str->flag[MINUS] == 0)
			while (d--)
				ft_putchar_fd(c, 1);
		ft_putstr_fd(s, 1);
		if (str->flag[MINUS] == 1)
			while (d--)
				ft_putchar_fd(' ', 1);
		str->len += str->width;
	}
	else
	{
		ft_putstr_fd(s, 1);
		str->len += ft_strlen(s);
	}
	return (str);
}

static char			*precision_char(int p, char *s, int p_m, int a)
{
	char	*new;
	int		s_len;
	int		i;

	i = 0;
	s_len = (int)ft_strlen(s);
	if (s_len > p && p_m == 0)
	{
		new = (char *)ft_calloc(p + 1, sizeof(char));
		ft_strlcpy(new, s, p + 1);
	}
	else
	{
		new = (char *)ft_calloc(s_len + 1, sizeof(char));
		ft_strlcpy(new, s, s_len + 1);
	}
	if (a == 1)
		free(s);
	return (new);
}

t_info				*put_string(t_info *str)
{
	char	*s;
	int		a;
	int		i;

	a = 0;
	s = va_arg(str->list, char*);
	if (s == NULL)
	{
		s = (char *)ft_calloc(7, sizeof(char));
		ft_strlcpy(s, "(null)", 7);
		a = 1;
	}
	if (str->flag[POINT] != 0)
	{
		s = precision_char(str->precision, s, str->p_minus, a);
		a = 1;
	}
	i = str->width > (int)ft_strlen(s) ? 1 : 0;
	str = put_s(str, s, str->flag[ZERO] == 1 ? '0' : ' ', i);
	if (a == 1)
		free(s);
	str->string++;
	return (str);
}
