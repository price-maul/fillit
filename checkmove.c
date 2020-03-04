/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:15:43 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/04 21:18:40 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		blockletter(char *blockcode, char *buf, char c, int xyjbm[5])
{
	if (buf[xyjbm[0] + 5 * xyjbm[1]] == '.')
	{
		blockcode[xyjbm[2]] = c;
		xyjbm[2]++;
		return (1);
	}
	return (-1);
}

void	checkright(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'r';
	xyjbm[0]++;
}

void	checkleft(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'l';
	xyjbm[0]--;
}

void	checkdown(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'd';
	xyjbm[1]++;
}
