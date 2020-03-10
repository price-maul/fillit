/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 19:48:57 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/22 18:02:41 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*string;

	if (!(string = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_memset(string, '\0', size + 1);
	return (string);
}
