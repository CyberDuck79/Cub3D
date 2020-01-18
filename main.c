/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:20:33 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/18 17:59:46 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "cub3d.h"

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

static void	mlx_win_init(t_cub3d *cub)
{
	char	*title;

	title = ft_strjoin("cub3D : ", cub->map.map_name);
	cub->mlx = mlx_init();
	cub->win = mlx_new_window(cub->mlx, cub->wx, cub->wy, title);
	free((void*)title);
}

int			main(int ac, char **av)
{
	t_cub3d	cub;
	t_error	error;

	if (ac < 2)
		return (print_error(ARGUMENT));
	ft_bzero(&cub, sizeof(t_cub3d));
	if ((error = file_parser(&cub, av[1])))
		return (print_error(error));
	mlx_win_init(&cub);
	return (0);
}
