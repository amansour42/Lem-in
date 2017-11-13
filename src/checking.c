/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:15:43 by amansour          #+#    #+#             */
/*   Updated: 2017/11/13 14:47:39 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_nbr_ants(t_env *e, char *line)
{
	if ((A = ft_atoi(line)) <= 0)
		ft_error(ANTNBR);
	return (1);
}

int		check_start_end(t_env *e, char *line, int i)
{
	if (!RNBR && ft_strcmp(line, "##start"))
		ft_error(NOSTART);
	if (!RNBR && !ft_strcmp(line, "##start"))
	{
		RNBR += 1;
		return (1);
	}
	if (line[0] == '#' && line[1] != '#')
		return (1);
	if (!ft_strcmp(line, "##end"))
		return (0);
	fill_room(e, line);
	RNBR += 1;
	return (1);
}

void	check_map(t_env *e, char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return ;
	printf("line = %s\n", line);
	fill_room(e, line);
}

static t_room	*find_room(t_env *e, char *str)
{
	t_room *r;

	r  = R;
	while (r)
	{
		if (!ft_strcmp(r->name, str))
			return (r);
		r = r->next;
	}
	return (r);
}

void	check_tubes(t_env *e, char *line)
{
	t_room *r1;
	t_room *r2;
	char    **s;

	while (1)
	{
		if (line[0] == '#')
		{
			free(line);
			if (!get_next_line(0, &line))
				break ;
			continue ;
		}
		s = ft_strsplit(line , '-');
		free(line);
		if (length(s) != 2)
		{
			clean_split(s);
			delete_room(&R);
			ft_error(INVALIDTUBE);
		}
		if (!(r1 = find_room(e, s[0])) || !(r2 = find_room(e, s[1])))
		{
			clean_split(s);
			delete_room(&R);
			ft_error(INVALIDTUBE);
		}
		add_tube(&(r1->tube), r2->name);
		add_tube(&(r2->tube), r1->name);
		if (!get_next_line(0, &line))
			break;
	}
}
