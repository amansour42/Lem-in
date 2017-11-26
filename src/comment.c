/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 11:39:38 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:20:51 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_iscomment(char *line)
{
	return (line[0] == '#' && ft_strcmp(line, "##start")
			&& ft_strcmp(line, "##end"));
}

void	add_comment(t_env *e, char *line)
{
	t_comment *c1;
	t_comment *c2;

	if ((c1 = (t_comment*)malloc(sizeof(t_comment))))
	{
		c1->next = NULL;
		c1->str = ft_strdup(line);
		c1->line = CURR;
		if (!C)
			C = c1;
		else
		{
			c2 = C;
			while (c2->next)
				c2 = c2->next;
			c2->next = c1;
		}
	}
	return ;
}

void	delete_first_comment(t_comment **c)
{
	t_comment *tmp;

	tmp = *c;
	*c = (*c)->next;
	free(tmp->str);
	free(tmp);
}

void	delete_comment(t_comment **c)
{
	while (*c)
		delete_first_comment(c);
}
