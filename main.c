/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:13:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 17:10:41 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"

static int	events(int key, t_env *env)
{
	t_line *line;

	if (key == ENTER_KEY)
	{
		line = line_init(vect2_init(10, 10), vect2_init(200, 200));
		draw_line(env, line, 0x00FFFFFF);
		change_line_coord(line, 50, 50, 400, 500);
		draw_line(env, line, 0x00FFFFFF);
		mlx_put_image_to_window(env->mp, env->wp, env->img->ip, 0, 0);
		free_line(line);
	}
	if (key == SPACE_KEY)
		clear_env(env);
	if (key == ESCAPE_KEY)
		del_env(env);
	return (0);
}

int			main(void)
{
	t_env	env;

	new_env(&env, WIN_X, WIN_Y, "Cub3D");
	mlx_key_hook(env.wp, events, &env);
	mlx_loop(env.mp);
	return (0);
}
