/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 14:33:11 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/23 13:22:21 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		size;
	int		neg;
	int		tmp;
	char	*array;

	neg = 0;
	if (n < 0)
		neg = 1;
	tmp = n;
	size = 1;
	while ((tmp /= 10))
		size++;
	array = ft_strnew(size + neg);
	if (array == NULL)
		return (NULL);
	if (neg)
		array[0] = '-';
	while (size--)
	{
		array[size + neg] = (neg ? -(n % 10) : (n % 10)) + '0';
		n /= 10;
	}
	return (array);
}
