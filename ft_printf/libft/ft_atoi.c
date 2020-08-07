/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 23:22:22 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 04:25:17 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *n)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	while (n[i] >= '0' && n[i] <= '9' && n[i])
	{
		result *= 10;
		result += (long)(n[i] - 48);
		i++;
	}
	return (result);
}
