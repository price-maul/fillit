/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:47:34 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/22 17:47:42 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *stak, const char *ndl, size_t len)
{
	char	*dst;
	char	*src;
	size_t	i;
	size_t	j;

	dst = (char *)stak;
	src = (char *)ndl;
	i = 0;
	j = 0;
	if (!src[j])
		return ((char *)stak);
	while (dst[i] && i < len)
	{
		j = 0;
		while (dst[i + j] == src[j] && src[j] != '\0' && i + j < len)
		{
			j++;
			if (src[j] == '\0')
				return ((char *)stak + i);
		}
		i++;
	}
	return (NULL);
}
