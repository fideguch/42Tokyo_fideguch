/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 03:17:18 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 17:26:35 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info	*precision_processing(t_info *str)
{
	if (*str->string != '.')
	{
		str->p_default = 1;
		return (str);
	}
	str->string++;
	if ((str->precision = ft_atoi((char *)str->string)) == 0 \
	&& *str->string == '*')
		str->precision = va_arg(str->list, int);
	if (str->precision < 0)
		str->p_minus = 1;
	while (ft_isdigit(*str->string) || *str->string == '*')
		str->string++;
	str->flag[POINT] = 1;
	return (str);
}

t_info	*width_processing(t_info *str)
{
	if ((str->width = ft_atoi((char *)str->string)) == 0 \
	&& *str->string == '*')
	{
		str->width = va_arg(str->list, int);
		if (str->width < 0)
		{
			str->width *= -1;
			str->flag[MINUS] = 1;
		}
	}
	while (ft_isdigit(*str->string) || *str->string == '*')
		str->string++;
	return (str);
}

t_info	*flag_processing(t_info *str)
{
	while (*str->string == '0' || *str->string == '-')
	{
		if (*str->string == '-')
			str->flag[MINUS] = 1;
		if (*str->string == '0')
			str->flag[ZERO] = 1;
		str->string++;
	}
	return (str);
}

t_info	*put_process_result(t_info *str)
{
	if (*str->string == '%')
		str = put_per(str);
	else if (*str->string == 'i' || *str->string == 'd')
		str = put_int(str);
	else if (*str->string == 'c')
		str = put_char(str);
	else if (*str->string == 's')
		str = put_string(str);
	else if (*str->string == 'p')
		str = put_pointer(str);
	else if (*str->string == 'u')
		str = put_unsigned_int(str);
	else if (*str->string == 'x' || *str->string == 'X')
		str = put_unsigned_int_hex(str);
	else
		return (str);
	return (str);
}

t_info	*process(t_info *str)
{
	clean_flags(str);
	str = flag_processing(str);
	str = width_processing(str);
	str = precision_processing(str);
	str = put_process_result(str);
	return (str);
}
