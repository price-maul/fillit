/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:25:57 by pmaul             #+#    #+#             */
/*   Updated: 2019/11/24 17:29:20 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_search_n(char *buf)
{
	int			i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*change(char **buf)
{
	char		*ptr;
	char		*temp;
	int			i;
	int			len;

	len = 0;
	if (*buf)
		len = ft_strlen(*buf);
	temp = ft_memchr(*buf, '\n', len);
	i = temp - *buf;
	if ((ptr = (char*)malloc(sizeof(char) * (i + 1))))
	{
		ft_memcpy(ptr, *buf, i);
		ptr[i] = '\0';
		temp = *buf;
		*buf = ft_strsub(*buf, i + 1, len);
		free(temp);
		return (ptr);
	}
	return (NULL);
}

static int		read_last_line(char **buf, char **line, int fd, int res)
{
	if (ft_search_n(buf[fd]))
	{
		*line = change(&buf[fd]);
		return (1);
	}
	if (res == 0 && ft_strlen(buf[fd]))
	{
		*line = buf[fd];
		buf[fd] = NULL;
		return (1);
	}
	return (0);
}

static int		check(char **buf, char *tmp, int fd)
{
	if (!(buf[fd] = ft_strjoin(buf[fd], tmp)))
	{
		free(buf[fd]);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buf[12000];
	int			res;
	char		tmp[BUFF_SIZE + 1];
	char		*tmp2;

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > 12000
		|| (res = read(fd, tmp, 0)) < 0)
		return (-1);
	if (buf[fd] == NULL)
		buf[fd] = ft_strnew(1);
	while ((res = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[res] = '\0';
		tmp2 = buf[fd];
		if (check(buf, tmp, fd))
			return (-1);
		free(tmp2);
		if (ft_search_n(buf[fd]))
			break ;
	}
	if (read_last_line(buf, line, fd, res))
		return (1);
	return (0);
}
