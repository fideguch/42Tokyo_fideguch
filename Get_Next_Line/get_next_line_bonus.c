/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fideguch <fideguch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 23:29:58 by fideguch          #+#    #+#             */
/*   Updated: 2020/07/29 14:06:47 by fideguch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	make_new_line(char **line, char **save, char *n_l, int f)
{
	char	*tmp;

	if (!(*line = ft_strdup(*save)))
	{
		free(*save);
		*save = NULL;
		return (1);
	}
	if (f == 1)
	{
		if (!(tmp = ft_strdup(n_l + 1)))
		{
			free(*save);
			*save = NULL;
			return (1);
		}
		free(*save);
		*save = tmp;
	}
	else
	{
		free(*save);
		*save = NULL;
	}
	return (0);
}

static int	set_in_line(char **line, char **save, ssize_t data)
{
	int		f;
	char	*next_line;

	f = 0;
	if (data < 0)
	{
		free(*save);
		*save = NULL;
		return (-1);
	}
	if (*save == NULL)
	{
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	if ((next_line = ft_strchr(*save, '\n')) != 0)
	{
		*next_line = '\0';
		f = 1;
	}
	if (make_new_line(line, save, next_line, f) != 0)
		return (-1);
	return (f);
}

static int	join_or_dup(char **save, char **buf)
{
	char	*s;

	if (*save == NULL)
	{
		if (!(*save = ft_strdup(*buf)))
		{
			free(*buf);
			*buf = NULL;
			return (-1);
		}
	}
	else
	{
		if (!(s = ft_strjoin(*save, *buf)))
		{
			free(*buf);
			free(*save);
			*buf = NULL;
			*save = NULL;
			return (-1);
		}
		free(*save);
		*save = s;
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[256];
	char		*buf;
	ssize_t		data;

	if (fd < 0 || fd == 1 || fd == 2 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!(buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char))))
	{
		free(save[fd]);
		save[fd] = NULL;
		return (-1);
	}
	while ((data = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[data] = '\0';
		if (join_or_dup(&save[fd], &buf) == -1)
			return (-1);
		if (ft_strchr(save[fd], '\n') != 0)
			break ;
	}
	free(buf);
	buf = NULL;
	return (set_in_line(line, &save[fd], data));
}
