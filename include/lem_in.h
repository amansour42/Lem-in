/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:55:04 by amansour          #+#    #+#             */
/*   Updated: 2017/11/26 15:43:47 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# define L				e->l
# define CURR			e->current_line
# define A				e->a_nbr
# define R				e->r
# define RNBR			e->r_nbr
# define C				e->c
# define END			e->end
# define START			e->start
# define ANTNBR			"Invalid ANTS' NUMBER!\n"
# define INVALIDMAP		"INVALID MAP\n"
# define NOSTART		"NO COMMAND START\n"
# define NOEND			"NO COMMAND END\n"
# define WRONGROOM		"WRONG ROMM'S FORMAT\n"
# define INVALIDLINK	"INVALID TUBE\n"
# define NOLINKS		"NOLINKS\n"

typedef struct			s_comment
{
	char				*str;
	int					line;
	struct s_comment	*next;
}						t_comment;

typedef struct		s_link
{
	char			*name;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_room	*next;
	t_link			*link;
	int				start;
	int				end;
}					t_room;

typedef struct		s_env
{
	t_room			*r;
	t_comment		*c;
	t_link			*l;
	int				r_nbr;
	int				a_nbr;
	int				current_line;
	char			*start;
	char			*end;
}					t_env;

int					main(void);
/*
 * checking
 */
void				check_nbr_ants(t_env *e);
void				check_start(t_env *e);
int					check_end(t_env *e, char *line);
void				check_map(t_env *e, char *line);
void				check_link(t_env *e, char *str);
void				add_link(t_link **link, char *str);
void				clean_split(char **str);
int					length(char **str);
/*
 * error
 */
int					ft_error(char *str);
/*
 *room
 */
void				fill_room(t_env *e, char *str, int end);
void				delete_room(t_room **r);
/*
 * map
 */
void				init_map(t_env *env);
/*
 * extra
 */
void				print_ants(t_env *e);
/*
 * comment
 */
void				add_comment(t_env *e, char *line);
int					ft_iscomment(char *line);
void				delete_first_comment(t_comment **c);
void				delete_comment(t_comment **c);
/*
 * link
 */
void				delete_link(t_link **link);
void				delete_first_link(t_link **link);
#endif
