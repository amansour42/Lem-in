/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:45:37 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:22:51 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	add_link(t_link **tube, char *str)
{
	t_link *tmp;
	t_link *list;

	tmp = NULL;
	if ((tmp = (t_link*)malloc(sizeof(t_link))))
	{
		tmp->name = ft_strdup(str);
		tmp->next = NULL;
		if (!*tube)
			*tube = tmp;
		else
		{
			list = *tube;
			while (list->next)
				list = list->next;
			list->next = tmp;
		}
	}
	return ;
}

void	delete_first_link(t_link **link)
{
	t_link *tmp;

	tmp = *link;
	*link = (*link)->next;
	free(tmp->name);
	free(tmp);
	return ;
}

void	delete_link(t_link **link)
{
	while (*link)
		delete_first_link(link);
}
