/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infomalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 01:45:42 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/03 08:13:12 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_infomalloc(size_t size)
{
	void	*content;

	content = malloc(size);
	if (!content)
		return (NULL);
	ft_bzero(content, size);
	return (content);
}
