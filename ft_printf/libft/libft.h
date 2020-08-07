/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 08:07:02 by fideguch          #+#    #+#             */
/*   Updated: 2020/08/05 19:07:28 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

char			*ft_itoa(int n);
int				ft_atoi(const char *n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			*ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t n, size_t size);
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			*ft_infomalloc(size_t size);
int				ft_strlcpy(char *dest, const char *src, size_t n);
void			ft_puthex(unsigned long long num, int plen, int d);
char			*ft_unsigned_itoa(unsigned int n);

#endif
