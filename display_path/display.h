/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 14:29:47 by amansour          #+#    #+#             */
/*   Updated: 2017/11/27 14:55:49 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H
# include "minilibx/mlx.h"
# define ABS(x) (x < 0) ? -x : x;
# define WIN		e->win
# define MLX		E->MLX

typedef struct		s_dot
{
	int				x;
	int				y;
	char			*name;
	int				c;
}					t_dot;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_dot			*pt;
	int				max_x;
	int				max_y;
	int				min_x;
	int				min_y;
	int				incx;
	int				incy;
	int				dx;
	int				dy;
}					t_env;

#endif
