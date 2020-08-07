/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 03:03:30 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/07 00:45:08 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>

# define INT_MIN	-2147483648
# define MIN_LEN	11

# define MINUS		0
# define ZERO		1
# define POINT		2

typedef	struct		s_info
{
	va_list		list;
	int			len;
	const char	*string;
	int			flag[3];
	int			width;
	int			precision;
	int			p_minus;
	int			p_default;
}					t_info;

int					ft_printf(const char *format, ...);
void				clean_flags(t_info *s);
t_info				*process(t_info *str);
t_info				*flag_processing(t_info *str);
t_info				*width_processing(t_info *str);
t_info				*precision_processing(t_info *str);
char				*precision_tmp(int p, char *s, int m, int d);
t_info				*put_result_mina(t_info *str, int width, char *s);
t_info				*put_result(t_info *str, char *s, char c, int m);
t_info				*put_int(t_info *str);
t_info				*put_char(t_info *str);
t_info				*put_string(t_info *str);
t_info				*put_pointer(t_info *str);
t_info				*put_unsigned_int(t_info *str);
char				*casthex(unsigned int num, int plen, char a);
t_info				*put_unsigned_int_hex(t_info *str);
t_info				*put_per(t_info *str);

#endif
