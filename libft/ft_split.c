/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:15:53 by pmaul             #+#    #+#             */
/*   Updated: 2020/03/06 20:28:17 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	my_countwords(char *s, char c)
{
	size_t		count;
	char		found;
	size_t		i;

	count = 0;
	i = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!found)
			{
				count++;
				found = 1;
			}
		}
		else if (found)
			found = 0;
		i++;
	}
	return (count);
}

static char		*my_getnextword(char *s, char c, size_t *idx)
{
	long		begin;
	long		end;
	char		*substr;

	begin = *idx;
	while (s[begin] == c)
		begin++;
	end = begin;
	while (s[end] && s[end] != c)
		end++;
	end--;
	substr = ft_substr(s, begin, end - begin + 1);
	*idx = end + 1;
	return (substr);
}

char			**ft_split(char const *s, char c)
{
	size_t		count;
	char		**splitted;
	size_t		i;
	size_t		idx;

	if (!s)
		return (NULL);
	count = my_countwords((char *)s, c);
	if (!(splitted = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	splitted[count] = (char *)NULL;
	i = 0;
	idx = 0;
	while (count)
	{
		splitted[i] = my_getnextword((char *)s, c, &idx);
		i++;
		count--;
	}
	return (splitted);
}
