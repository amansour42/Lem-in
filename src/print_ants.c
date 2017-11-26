/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 14:53:11 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:57:57 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_ants(t_env *e)
{
	t_room	*r;
	t_link	*t;
	int		i;

	i = 2;
	printf("%d\n", A);
	r = R;
	while (r)
	{
		if (C && C->line == i)
		{
			ft_putendl(C->str);
			++i;
			delete_first_comment(&C);
			continue;
		}
		if (!ft_strcmp(START, r->name))
			printf("##start\n");
		if (!ft_strcmp(END, r->name))
			printf("##end\n");
		printf("ROOM = %s, x = %d, y = %d\n", r->name, r->x, r->y);
		t = r->link;
		/*printf("LINKS\n");
		while (t)
		{
			printf("%s-%s\n", r->name, t->name);
			t = t->next;
		}*/
		r = r->next;
		++i;
	}
	while (L)
	{
		if (C && C->line == i)
		{
			ft_putendl(C->str);
			++i;
			delete_first_comment(&C);
			continue;
		}
		printf("%s\n", L->name);
		delete_first_link(&L);
	}
	while (C)
	{
		printf("%s\n", C->str);
		delete_first_comment(&C);
	}
}
