/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:23:21 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/23 18:41:22 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr_d;
	unsigned char	*ptr_s;

	if (n == 0 || s1 == s2)
		return (s1);
	ptr_d = (unsigned char *)s1;
	ptr_s = (unsigned char *)s2;
	while (n-- > 0)
	{
		ptr_d[n] = ptr_s[n];
	}
	return (s1);
}
