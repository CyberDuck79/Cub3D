/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:33 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/07 15:28:44 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3D.h"

static int	ft_close(void)
{
	exit(1);
	return (0);
}

static int	print_error(t_error *error)
{
	if (error == ARGUMENT)
		write(1, "Error\nUsage: cub3D \"map\"\n", 25);
	else if (error == FILE)
		write(1, "Error\nOpening file\n", 19);
	else if (error == EXTENSION)
		write(1, "Error\nFile extension\n", 21);
	else if (error == RESOLUTION)
		write(1, "Error\nResolution\n", 17);
	else if (error == TEXTURES)
		write(1, "Error\nTextures opening\n", 23);
	else if (error == COLORS)
		write(1, "Error\nFloor or sky color\n", 25);
	else if (error == MAP)
		write(1, "Error\nMap format\n", 17);
	return (0);
}

static void	mlx_win_init(t_cub3D *cub)
{
	char	*title;

	title = ft_strjoin("cub3D : ", cub->map_name);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, WINX, WINY, title);
	free((void*)title);
}
/*
void	cub3D_init(t_cub3D *cub)
{
	cub->x_pos = 3;
	cub->y_pos = 3;
	cub->x_dir = -1;
	cub->y_dir = 0;
	cub->x_plane = 0;
	cub->y_plane = 0.66;
	cub->ms = 0.05;
	cub->rs = 0.05;
	cub->move_up = 0;
	cub->move_down = 0;
	cub->move_left = 0;
	cub->move_right = 0;
	cub->x_text = 0;
	cub->y_text = 0;
	load_textures(cub);
}
*/
int		main(int ac, char **av)
{
	t_cub3D	cub;
	t_error	error;

	if (ac < 2)
		return (print_error(ARGUMENT));
	if ((error = map_parser(&cub, av[1])))
		return (print_error(error));
	mlx_win_init(&cub);
	/*
	cub.help = 1;
	cub3D_init(&cub);
	ray_casting(&cub);
	if (ac == 3 && check_option(av[2]))
		save_bmp(&cub);
	else
	{
		mlx_hook(cub.win, 17, 0L, ft_close, &cub);
		mlx_hook(cub.win, 2, (1L << 0), key_press, &cub);
		mlx_hook(cub.win, 3, (1L << 1), key_release, &cub);
		mlx_loop_hook(cub.mlx, move, &cub);
		mlx_loop(cub.mlx);
	}
	*/
	return (0);
}