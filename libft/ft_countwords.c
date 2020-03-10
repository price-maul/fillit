/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:29:35 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/24 13:29:43 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(const char *str, char delim)
{
	int	in_word;
	int	num_words;
	int i;

	in_word = 0;
	num_words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delim)
		{
			i++;
			in_word = 0;
		}
		else
		{
			if (in_word == 0)
			{
				in_word = 1;
				num_words++;
			}
			i++;
		}
	}
	return (num_words);
}
