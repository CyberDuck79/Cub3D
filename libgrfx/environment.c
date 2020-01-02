/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:40:20 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 16:03:35 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgrfx.h"

t_error	clear_env(t_env *env)
{
	clear_image(env->img);
	mlx_clear_window(env->mp, env->wp);
	return (NO_ERROR);
}

void	del_env(t_env *env)
{
	if (env != NULL)
	{
		if (env->img)
		{
			mlx_destroy_image(env->mp, env->img->ip);
			free(env->img);
		}
		mlx_destroy_window(env->mp, env->wp);
		system("leaks Cub3D");
		exit(0);
	}
}

t_error	new_env(t_env *env, int size_x, int size_y, char *title)
{
	env->wx = size_x;
	env->wy = size_y;
	if (!(env->mp = mlx_init()))
		return (MLX_ERROR);
	if (!(env->wp = mlx_new_window(env->mp, env->wx, env->wy, title)))
		return (WINDOW_ERROR);
	if (!(env->img = new_image(env, env->wx, env->wy)))
	{
		mlx_destroy_window(env->mp, env->wp);
		return (IMG_ERROR);
	}
	return (NO_ERROR);
}
