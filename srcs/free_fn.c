/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 19:30:07 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/08 19:30:11 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	stck_free(t_tetris *stack)
{
	t_tetris *tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp);
	}
}

void	stck_free_coord(t_tetris *stack)
{
	t_tetris *tmp;

	tmp = NULL;
	while (stack)
	{
		tmp = stack;
		stack = tmp->next;
		free(tmp->tet_id);
		free(tmp);
	}
}

void	free_grid(char **grid, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&grid[i]);
		i++;
	}
	free(grid);
}
