/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:37:51 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/21 11:44:29 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	char	*dst;
	char	*src;
	int		i;
	int		j;

	dst = (char *)haystack;
	src = (char *)needle;
	i = 0;
	j = 0;
	if (!src[j])
		return ((char *)haystack);
	while (dst[i])
	{
		j = 0;
		while (dst[i + j] == src[j] && src[j] != '\0')
		{
			j++;
			if (src[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
