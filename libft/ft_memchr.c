/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:35:28 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/22 20:20:15 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *a, int b, size_t c)
{
	size_t		i;
	const char	*j;

	i = 0;
	j = a;
	while (i < c)
	{
		if ((unsigned char)j[i] == (unsigned char)b)
			return ((char *)j + i);
		i++;
	}
	return (NULL);
}
