/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:35:24 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/06 19:50:43 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		i++;
	}
	j = 0;
	while (dstsize != 0 && j < (dstsize - 1) && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	if (j < dstsize)
	{
		dst[j] = '\0';
	}
	return (i);
}
