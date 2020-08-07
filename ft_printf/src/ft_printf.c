/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 01:36:58 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 17:22:19 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	clean_flags(t_info *s)
{
	s->flag[MINUS] = 0;
	s->flag[ZERO] = 0;
	s->flag[POINT] = 0;
	s->width = 0;
	s->precision = 0;
	s->p_default = 0;
	s->p_minus = 0;
	return ;
}

int		ft_printf(const char *format, ...)
{
	t_info	*str;

	str = (t_info *)ft_infomalloc(sizeof(t_info));
	va_start(str->list, format);
	str->len = 0;
	str->string = format;
	while (*str->string)
	{
		if (*str->string && *str->string == '%')
		{
			str->string++;
			str = process(str);
			continue ;
		}
		ft_putchar_fd(*str->string, 1);
		str->len++;
		str->string++;
	}
	va_end(str->list);
	free(str);
	return (str->len);
}
