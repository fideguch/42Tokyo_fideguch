/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ints_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 05:19:46 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/07 01:09:53 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

t_info		*put_result(t_info *str, char *s, char c, int m)
{
	int		diff;

	diff = str->width - ft_strlen(s);
	if (m == 1)
		ft_putchar_fd('-', 1);
	while (diff--)
	{
		ft_putchar_fd(c, 1);
		str->len++;
	}
	ft_putstr_fd(m == 1 ? s + 1 : s, 1);
	return (str);
}

t_info		*put_result_mina(t_info *str, int width, char *s)
{
	int		diff;

	diff = width - ft_strlen(s);
	ft_putstr_fd(s, 1);
	while (diff--)
	{
		ft_putchar_fd(' ', 1);
		str->len++;
	}
	return (str);
}

char		*precision_tmp(int p, char *s, int m, int d)
{
	char	*p_s;
	int		i;
	int		a;

	a = 0;
	i = 0;
	if (p > (int)ft_strlen(s))
	{
		i = p - ft_strlen(s);
		p_s = (char *)ft_calloc(m == 1 ? p + 2 : p + 1, sizeof(char));
	}
	else
		p_s = (char *)ft_calloc(m == 1 ? \
		ft_strlen(s) + 2 : ft_strlen(s) + 1, sizeof(char));
	if (m == 1)
		p_s[a++] = '-';
	while (i--)
		p_s[a++] = '0';
	while (*s)
		p_s[a++] = *(s++);
	if (p == 0 && *p_s == '0' && d == 0)
		free(p_s);
	return (p == 0 && *p_s == '0' && d == 0 ? "" : p_s);
}
