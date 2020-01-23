/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:33 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 13:00:34 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

int			ft_close(t_cub3d *cub)
{
	escape_free_map(cub->map.map, cub->map.y);
	mlx_destroy_image(cub->mlx, cub->img.ptr);
	mlx_destroy_window(cub->mlx, cub->win);
	system("leaks a.out");
	exit(1);
	return (0);
}

// look at perror ?
static int	print_error(t_error error)
{
	write(1, "Error\n", 6);
	if (error == ARGUMENT)
		write(1, "Usage: cub3D \"map\"\n", 19);
	else if (error == OPEN_FILE)
		write(1, "Cannot opening file\n", 20);
	else if (error == EXTENSION)
		write(1, "Bad file extension\n", 19);
	else if (error == SYNTAX)
		write(1, "Invalid syntax in map file.\n", 28);
	else if (error == RESOLUTION)
		write(1, "Invalid resolution\n", 19);
	else if (error == TEXTURES)
		write(1, "Cannot opening a texture file.\n", 31);
	else if (error == COLORS)
		write(1, "Invalid floor or sky color\n", 27);
	else if (error == MAP)
		write(1, "Map syntax\n", 11);
	return (0);
}

static void	camera_init(t_cam *cam, t_map *map)
{
	cam->pos_x = (double)map->start_x;
	cam->pos_y = (double)map->start_y;
	if (map->start_dir == 'N' || map->start_dir == 'S')
	{
		cam->dir_y = map->start_dir == 'N' ? -1 : 1;
		cam->plane_x = map->start_dir == 'N' ? -0.80 : 0.80;
	}
	else if (map->start_dir == 'W' || map->start_dir == 'E')
	{
		cam->dir_x = map->start_dir == 'W' ? -1 : 1;
		cam->plane_y = map->start_dir == 'W' ? -0.80 : 0.80;
	}
	cam->ms = 0.05;
	cam->rs = 0.05;
}

static void	env_init(t_cub3d *cub)
{
	char	*title;

	title = ft_strjoin("cub3D : ", cub->map.map_name);
	free((void*)cub->map.map_name);
	cub->map.map_name = NULL;
	cub->win = mlx_new_window(cub->mlx, cub->wx, cub->wy, title);
	free((void*)title);
	cub->img.ptr = mlx_new_image(cub->mlx, cub->wx, cub->wy);
	cub->img.addr = (int*)mlx_get_data_addr(cub->img.ptr, &cub->img.bpp,\
	&cub->img.size_l, &cub->img.endian);
	cub->img.bpp /= 8;
}

int			main(int ac, char **av)
{
	t_cub3d	cub;
	t_error	error;

	if (ac < 2)
		return (print_error(ARGUMENT));
	ft_bzero(&cub, sizeof(t_cub3d));
	cub.mlx = mlx_init();
	if ((error = file_parser(&cub, av[1])))
		return (print_error(error));
	env_init(&cub);
	camera_init(&cub.cam, &cub.map);
	mlx_hook(cub.win, 17, 0L, ft_close, &cub);
	mlx_hook(cub.win, 2, (1L << 0), key_press, &cub);
	mlx_hook(cub.win, 3, (1L << 1), key_release, &cub);
	mlx_loop_hook(cub.mlx, move, &cub);
	mlx_loop(cub.mlx);
	return (0);
}
