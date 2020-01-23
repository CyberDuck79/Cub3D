/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:33 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 09:49:21 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

int		ft_close(void)
{
	//escape_free_map()
	exit(1);
	return (0);
}

//// change to perror after complete ray_casting
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

static void	cub3d_init(t_cub3d *cub)
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
	cub->cam.pos_x = (double)cub->map.start_x;
	cub->cam.pos_y = (double)cub->map.start_y;
	if (cub->map.start_dir == 'N' || cub->map.start_dir == 'S')
	{
		cub->cam.dir_y = cub->map.start_dir == 'N' ? -1 : 1;
		cub->cam.plane_x = cub->map.start_dir == 'N' ? -0.80 : 0.80;
	}
	else if (cub->map.start_dir == 'W' || cub->map.start_dir == 'E')
	{
		cub->cam.dir_x = cub->map.start_dir == 'W' ? -1 : 1;
		cub->cam.plane_y = cub->map.start_dir == 'W' ? -0.80 : 0.80;
	}
	cub->cam.ms = 0.05;
	cub->cam.rs = 0.05;
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
	cub3d_init(&cub);
	mlx_hook(cub.win, 17, 0L, ft_close, &cub);
	frame(&cub, &cub.cam);
	mlx_loop(cub.mlx);
	return (0);
}
