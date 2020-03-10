/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:12:50 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/23 12:41:27 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_atoi(const char *str)
{
	int						i;
	int						sign;
	unsigned long long int	num;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == 9 || str[i] == 10 || str[i] == 11
			|| str[i] == 12 || str[i] == 13 || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
		if (num >= 9223372036854775807)
			return (sign == 1 ? -1 : 0);
	}
	return (num * sign);
}
