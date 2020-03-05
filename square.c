/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:19:09 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/05 17:30:28 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**square(int size)
{
	int		i;
	char	**sq;

	i = 0;
	if (!(sq = (char**)malloc(sizeof(*sq) * size)))
		return (NULL);
	while (i < size)
	{
		if (!(sq[i] = malloc(sizeof(*sq) * size + 1)))
			return (NULL);
		ft_memset(sq[i], '.', size);
		sq[i][size] = '\0';
		i++;
	}
	return (sq);
}

void		place(char **square, char *blockcode, int y, int x)
{
	int		i;

	i = 0;
	if (ft_isalpha(blockcode[i]))
		square[y][x] = blockcode[i];
	while (blockcode[i] != '\0')
	{
		if (blockcode[i] == 'r' || blockcode[i] == 'l' || blockcode[i] == 'd')
		{
			if (blockcode[i] == 'r')
				x++;
			else if (blockcode[i] == 'l')
				x--;
			else if (blockcode[i] == 'd')
				y++;
			i++;
			if (ft_isalpha(blockcode[i]))
				square[y][x] = blockcode[i];
		}
		i++;
	}
}

void		erase(char **square, char *blockcode, int y, int x)
{
	int		i;

	i = 0;
	if (ft_isalpha(blockcode[i]))
		square[y][x] = '.';
	while (blockcode[i] != '\0')
	{
		if (blockcode[i] == 'r' || blockcode[i] == 'l' || blockcode[i] == 'd')
		{
			if (blockcode[i] == 'r')
				x++;
			else if (blockcode[i] == 'l')
				x--;
			else if (blockcode[i] == 'd')
				y++;
			i++;
			if (ft_isalpha(blockcode[i]))
				square[y][x] = '.';
		}
		i++;
	}
}
