/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 12:28:33 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/23 12:15:05 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *d;

	d = (unsigned char*)dest;
	if (dest > src)
		while (len--)
			*((unsigned char*)(dest + len)) = *(unsigned char*)(src + len);
	else if (dest < src)
		while (len--)
		{
			*(unsigned char*)dest = *(unsigned char*)src;
			++dest;
			++src;
		}
	return (d);
}
