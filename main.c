/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:13:50 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/03 15:55:19 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3D.h"
#include "utils.h"

static int	key_press(int key)
{
	if (key == ESCAPE_KEY)
		exit(1);
	return (0);
}

static int	loop(t_cub *cub)
{
	(void)cub;
	return (0);
}

static int	close_window(void)
{
	exit(1);
	return (0);
}

static void	cub3D_init(t_env *env, t_cub *cub)
{
	cub->env = env;
	mlx_do_key_autorepeaton(env->mp);
	mlx_do_sync(env->mp);
}

int			main(int ac, char **av)
{
	t_env	env;
	t_cub	cub;

	// faire le resize
	if (ac != 3 || (env.wx = atoi(av[1])) < 1 || (env.wx = atoi(av[2])) < 1)
		return (0);
	new_env(&env, env.wx, env.wx, "Cub3D");
	cub3D_init(&env, &cub);
	mlx_hook(env.wp, X_BUTTON_EVENT, (1L<<17), close_window, &env);
	mlx_hook(env.wp, KEY_PRESS_EVENT, (1L<<0), key_press, &cub);
	mlx_loop_hook(env.mp, loop, &cub);
	mlx_loop(env.mp);
	return (0);
}
