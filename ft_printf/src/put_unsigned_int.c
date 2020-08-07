/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 07:06:32 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 17:13:37 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info		*put_unsigned_int(t_info *str)
{
	char			*s;
	char			*str_tmp;

	if (str->flag[POINT] == 1)
		str->flag[ZERO] = 0;
	s = ft_unsigned_itoa(va_arg(str->list, unsigned int));
	str_tmp = precision_tmp(str->precision, s, 0, str->p_default);
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
	str->len += ft_strlen(str_tmp);
	str->string++;
	if (!(str->precision == 0 && *str_tmp == '\0' && str->p_default == 0))
		free(str_tmp);
	free(s);
	return (str);
}
