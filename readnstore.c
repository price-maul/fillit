/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readnstore.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:20:52 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/05 21:21:34 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "fillit.h"

#define BUF_SIZE 21

static void		creatlistfirst(t_list **fb, t_list **blocks, char *buf, int *i)
{
	*fb = ft_lstnew(encode(buf, 'A' + *i), sizeof(t_tetri));
	*blocks = *fb;
}

static void		creatlist(t_list **blocks, t_list **next, char *buf, int *i)
{
	*next = ft_lstnew(encode(buf, 'A' + *i), sizeof(t_tetri));
	*blocks = *next;
}

t_list			*readnstore(int fd)
{
	int			ret;
	int			i;
	char		buf[BUF_SIZE + 1];
	t_list		*blocks;
	t_list		*firstblock;

	i = 0;
	firstblock = NULL;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(checkblock(buf, ret)))
			return (NULL);
		else
		{
			if (firstblock == NULL)
				creatlistfirst(&firstblock, &blocks, buf, &i);
			else
				creatlist(&blocks, &blocks->next, buf, &i);
			i++;
		}
	}
	if (ret == 0 && buf[20] != '\0')
		return (NULL);
	return (firstblock);
}
