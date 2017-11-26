/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:48:20 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:49:54 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	delete_room_end(t_room **r)
{
	t_room *tmp;
	t_room *ptmp;

	if (*r)
	{
		if (!((*r)->next))
		{
			free((*r)->name);
			free(*r);
			delete_link(&((*r)->link));
			*r = NULL;
		}
		else
		{
			tmp = *r;
			while ((tmp->next)->next)
				tmp = tmp->next;
			ptmp = tmp->next;
			tmp->next = NULL;
			free(ptmp->name);
			delete_link(&((*r)->link));
			free(ptmp);
		}
	}
	return ;
}

void	delete_room(t_room **r)
{
	while (*r)
		delete_room_end(r);
	*r = NULL;
	return ;
}
