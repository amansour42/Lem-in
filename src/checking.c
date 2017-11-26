/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:15:43 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:44:17 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	check_nbr_ants(t_env *e)
{
	char *line;

	if (get_next_line(0, &line) == 0)
		ft_error(INVALIDMAP);
	if ((A = ft_atoi(line)) <= 0)
		ft_error(ANTNBR);
	CURR = 1;
	free(line);
}

void		check_start(t_env *e)
{
	char *line;

	while (get_next_line(0, &line) && ft_iscomment(line))
	{
		CURR += 1;
		add_comment(e, line);
		free(line);
	}
	if (!line || ft_strcmp(line, "##start"))
	{
		if (line)
			free(line);
		ft_error(NOSTART);
	}
	if (!get_next_line(0, &line))
		ft_error(INVALIDMAP);
	RNBR += 1;
	CURR += 1;
	fill_room(e, line, 0);
	free(line);
}

int			check_end(t_env *e, char *line)
{
	CURR += 1;
	if (ft_iscomment(line))
	{
		add_comment(e, line);
		return (0);
	}
	if (!ft_strcmp(line, "##end"))
	{
		free(line);
		if (!get_next_line(0, &line))
		{
			delete_room(&R);
			delete_comment(&C);
			ft_error(NOEND);
		}
		fill_room(e, line, 1);
		free(line);
		return (1);
	}
	RNBR += 1;
	fill_room(e, line, 0);
	return (0);
}

void	check_map(t_env *e, char *line)
{
	CURR += 1;
	if (ft_iscomment(line))
	{
		add_comment(e, line);
		return ;
	}
	fill_room(e, line, 0);
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

void	check_link(t_env *e, char *line)
{
	t_room	*r1;
	t_room	*r2;
	char	**s;

	while (1)
	{
		CURR += 1;
		if (ft_iscomment(line))
		{
			add_comment(e, line);
			free(line);
			if (!get_next_line(0, &line))
				break ;
			continue ;
		}
		add_link(&L, line);
		s = ft_strsplit(line , '-');
		free(line);
		if (length(s) != 2)
		{
			clean_split(s);
			delete_room(&R);
			ft_error(INVALIDLINK);
		}
		if (!(r1 = find_room(e, s[0])) || !(r2 = find_room(e, s[1])))
		{
			clean_split(s);
			delete_room(&R);
			ft_error(INVALIDLINK);
		}
		add_link(&(r1->link), r2->name);
		add_link(&(r2->link), r1->name);
		if (!get_next_line(0, &line))
			break;
	}
}
