/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amansour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:35:29 by amansour          #+#    #+#             */
/*   Updated: 2017/11/27 14:46:02 by amansour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

static void	segment_point_x(t_dot pt, t_env *env, int color)
{
	int		cumul;
	int		i;

	i = 0;
	cumul = env->dx / 2;
	while (++i < env->dx)
	{
		pt.x += env->incx;
		cumul += env->dy;
		if (cumul >= env->dx)
		{
			cumul -= env->dx;
			pt.y += env->incy;
		}
		mlx_put_pixel(MLX, WIN, pt.x, pt.y, color);
	}
}

static void	segment_point_y(t_dot pt, t_env *env, int color)
{
	int	cumul;
	int	i;

	i = 0;
	cumul = env->dy / 2;
	while (++i < env->dy)
	{
		pt.y += env->incy;
		cumul += env->dx;
		if (cumul >= env->dy)
		{
			cumul -= env->dy;
			pt.x += env->incx;
		}
		write_one_pixel(pt, env, color);
	}
}

void		segment(t_dot pti, t_dot ptf, t_env *env)
{
	t_dot pt;

	env->dx = (int)(ptf.x - pti.x);
	env->dy = (int)(ptf.y - pti.y);
	env->incx = (env->dx > 0) ? 1 : -1;
	env->incy = (env->dy > 0) ? 1 : -1;
	env->dx = ABS(env->dx);
	env->dy = ABS(env->dy);
	pt.x = (int)pti.x;
	pt.y = (int)pti.y;
	pt.c = pti.c;
	write_one_pixel(pt, env, pt.c);
	if (env->dx > env->dy)
		segment_point_x(pt, env, ptf.c);
	else
		segment_point_y(pt, env, ptf.c);
}
