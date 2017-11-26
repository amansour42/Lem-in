/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:09:40 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:45:10 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main(void)
{
	t_env	e;
	char	*line;

	init_map(&e);
	check_nbr_ants(&e);
	check_start(&e);
	while (get_next_line(0, &line)== 1 && !check_end(&e, line))
		free(line);
	/*if (!line)//delete_comment
	{
		delete_room(&(e.r));
		ft_error(NOEND);
	}
	free(line);*/
	while (get_next_line(0, &line) && !(belong(line, '-')))
	{
		check_map(&e, line);
		free(line);
	}
	if (!line)//delete_comment
	{
		delete_room(&(e.r));
		ft_error(NOLINKS);
	}
	check_link(&e, line);
	print_ants(&e);
	return (0);
}
