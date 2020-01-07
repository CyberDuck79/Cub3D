/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:30:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/07 15:43:29 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

static t_error	check_extension(t_cub3D *cub, char *filename)
{
	size_t	len;

	if ((len = ft_strlen(filename)) < 5)
		return (EXTENSION);
	if (strcmp(".cub", filename + (len - 4)))
		return (EXTENSION);
	ft_strlcpy(cub->map_name, filename, len - 4);
	return (OK);
}

static t_error	check_map(t_cub3D *cub, char *map)
{
	if (get_resolution(cub, &map))
		return (RESOLUTION);
	else if (get_textures(cub, &map))
		return (TEXTURES);
	else if (get_colors(cub, &map))
		return (COLORS);
	else if (get_map(cub, &map))
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
		return (new = (char*)malloc(offset));
	if (!(new = read_file(fd, offset + count)))
		return (NULL);
	strncpy(new + offset, buf, BUFFER_SIZE);
	return (new);
}

t_error		map_parser(t_cub3D *cub, char *filename)
{
	char	*map;
	t_error	error;

	if ((error = check_extension(cub, filename)))
		return (error);
	if (!(map = read_file(open(filename, O_RDONLY), 0)))
		return (FILE);
	if ((error = check_map(cub, map)))
		return (error);
	//
	return (OK);
}