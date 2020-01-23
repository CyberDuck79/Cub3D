/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:25:19 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 17:05:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_error		parse_resolution(t_cub3d *cub, const char **file)
{
	if (cub->params & RES)
		return (RESOLUTION);
	cub->wx = ft_atoi(*file);
	if (cub->wx < MIN_WINX || cub->wx > MAX_WINX)
		return (RESOLUTION);
	skip_set(file, NUMBERS);
	skip_set(file, " ");
	cub->wy = ft_atoi(*file);
	if (cub->wy < MIN_WINY || cub->wy > MAX_WINY)
		return (RESOLUTION);
	skip_set(file, NUMBERS);
	cub->params |= RES;
	return (OK);
}

static char	*get_path(const char **file)
{
	char	*path;
	size_t	len;
	int		fd;

	len = 0;
	while ((*file)[len] && (*file)[len] != '\n')
		len++;
	if ((path = (char*)malloc(len + 1)) == NULL)
		return (NULL);
	ft_strlcpy(path, *file, len + 1);
	*file += len;
	fd = open(path, O_RDONLY);
	len = read(fd, path, 0);
	close(fd);
	if (len < 0)
	{
		free(path);
		return (NULL);
	}
	return (path);
}

static void	load_textures(t_cub3d *cub, char *path, size_t index, int size)
{
	cub->text[index].img = mlx_xpm_file_to_image(cub->mlx, path, &size, &size);
	cub->text[index].data = (int*)mlx_get_data_addr(
	cub->text[index].img,
	&cub->text[index].bpp,
	&cub->text[index].size_l,
	&cub->text[index].endian
	);
	cub->text[index].bpp /= 8;
}

t_error		parse_textures(t_cub3d *cub, const char **file, t_option option)
{
	char		*path;

	if (cub->params & option)
		return (TEXTURES);
	if ((path = get_path(file)) == NULL)
		return (TEXTURES);
	if (option == TEXT_NO)
		load_textures(cub, path, 0, 64);
	else if (option == TEXT_SO)
		load_textures(cub, path, 1, 64);
	else if (option == TEXT_WE)
		load_textures(cub, path, 2, 64);
	else if (option == TEXT_EA)
		load_textures(cub, path, 3, 64);
	else if (option == SPRITE)
		load_textures(cub, path, 4, 64);
	free(path);
	cub->params |= option;
	return (OK);
}

t_error		parse_colors(t_cub3d *cub, const char **file, t_option option)
{
	t_rgb	color;

	if (cub->params & option)
		return (COLORS);
	color.r = ft_atoi(*file);
	if (color.r < 0x0 || color.r > 0xFF)
		return (COLORS);
	skip_set(file, NUMBERS);
	skip_set(file, ",");
	color.g = ft_atoi(*file);
	if (color.g < 0x0 || color.g > 0xFF)
		return (COLORS);
	skip_set(file, NUMBERS);
	skip_set(file, ",");
	color.b = ft_atoi(*file);
	if (color.b < 0x0 || color.b > 0xFF)
		return (COLORS);
	skip_set(file, NUMBERS);
	if (option == FLOOR)
		cub->color[0] = color.r | color.g << 8 | color.b << 16;
	if (option == CEILING)
		cub->color[1] = color.r | color.g << 8 | color.b << 16;
	cub->params |= option;
	return (OK);
}
