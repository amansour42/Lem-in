/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:09:40 by amansour          #+#    #+#             */
/*   Updated: 2017/11/13 14:25:55 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(void)
{
	t_env	e;
	char	*line;

	init_map(&e);
	(get_next_line(0, &line) == 1) ? check_nbr_ants(&e, line) : ft_error(INVALIDMAP);
	free(line);
	while ((get_next_line(0, &line)) && (e.end = check_start_end(&e, line)))
		free(line);
	if (e.end)
	{
		delete_room(&(e.r));
		ft_error(NOEND);
	}
	while (get_next_line(0, &line) && !(belong(line, '-')))
	{
		check_map(&e, line);
		free(line);
	}
	if (!line)
	{
		delete_room(&(e.r));
		ft_error(NOTUBES);
	}
	check_tubes(&e, line);
	print_ants(&e);
	return (0);
}
