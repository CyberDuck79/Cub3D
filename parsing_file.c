/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:30:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 10:35:25 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_option	check_token(const char *str)
{
	if (!ft_strncmp("R ", str, 2))
		return (RES);
	if (!ft_strncmp("NO ", str, 3))
		return (TEXT_NO);
	if (!ft_strncmp("SO ", str, 3))
		return (TEXT_SO);
	if (!ft_strncmp("EA ", str, 3))
		return (TEXT_EA);
	if (!ft_strncmp("WE ", str, 3))
		return (TEXT_WE);
	if (!ft_strncmp("S ", str, 2))
		return (SPRITE);
	if (!ft_strncmp("F ", str, 2))
		return (FLOOR);
	if (!ft_strncmp("C ", str, 2))
		return (CEILING);
	return (ERROR);
}

static t_error	check_extension(t_cub3d *cub, const char *filename)
{
	size_t	len;

	if ((len = ft_strlen(filename)) < 5)
		return (EXTENSION);
	if (ft_strncmp(".cub", filename + (len - 4), 4))
		return (EXTENSION);
	if ((cub->map.map_name = (char*)malloc(len - 3)) == NULL)
		return (EXTENSION);
	ft_strlcpy(cub->map.map_name, filename, len - 3);
	return (OK);
}

static t_error	check_file(t_cub3d *cub, const char *file)
{
	t_option	opt;

	while (cub->params != (char)CONFIGURED)
	{
		skip_set(&file, SPACES);
		if ((opt = check_token(file)) == ERROR)
			return (SYNTAX);
		skip_set(&file, TOKENS);
		if (opt == RES && parse_resolution(cub, &file))
			return (RESOLUTION);
		if (opt >= TEXT_NO && opt <= SPRITE && parse_textures(cub, &file, opt))
			return (TEXTURES);
		if ((opt == FLOOR || opt == CEILING) && parse_colors(cub, &file, opt))
			return (COLORS);
	}
	skip_set(&file, SPACES);
	if (parse_map(&cub->map, file))
		return (MAP);
	return (OK);
}

static char		*read_file(int fd, size_t offset)
{
	char		buf[BUFFER_SIZE];
	char		*new;
	size_t		count;

	if (read(fd, buf, 0) < 0)
		return (NULL);
	if (!(count = read(fd, buf, BUFFER_SIZE)))
	{
		close(fd);
		return ((char*)ft_calloc(offset + 1, sizeof(char)));
	}
	if (!(new = read_file(fd, offset + count)))
		return (NULL);
	ft_memcpy(new + offset, buf, count);
	return (new);
}

t_error			file_parser(t_cub3d *cub, const char *filename)
{
	char	*file;
	t_error	error;

	if (check_extension(cub, filename))
		return (EXTENSION);
	if (!(file = read_file(open(filename, O_RDONLY), 0)))
		return (OPEN_FILE);
	if ((error = check_file(cub, file)))
		return (error);
	free(file);
	return (OK);
}
