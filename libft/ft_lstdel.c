/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaul <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:30:02 by pmaul             #+#    #+#             */
/*   Updated: 2019/09/22 16:34:55 by pmaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp_next;

	if (alst && *alst && del)
	{
		tmp = *alst;
		while (tmp)
		{
			tmp_next = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = tmp_next;
		}
		*alst = NULL;
	}
}
