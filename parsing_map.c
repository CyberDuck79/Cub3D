/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:15:07 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/18 17:49:17 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	get_mapsize(t_map *map, const char *file)
{
	while (*file != '\n')
	{
		if (is_valid(*file))
			map->map_x++;
		else if (*file != ' ')
			return (MAP);
		file++;
	}
	while (*file)
	{
		if (!is_valid(*file) && *file != ' ' && *file != '\n')
			return (MAP);
		else if (*file == '\n')
			map->map_y++;
		file++;
	}
	return (OK);
}

static int		**malloc_map(int map_x, int map_y)
{
	int		**map;
	int		index;

	index = 0;
	if ((map = (int**)malloc(sizeof(int*) * map_y)) == NULL)
		return (NULL);
	while (index < map_y)
	{
		if ((map[index] = (int*)malloc(sizeof(int) * map_x)) == NULL)
			return (escape_free_map(map, index));
		index++;
	}
	return (map);
}

static t_error	copy_map(t_map *map, const char *file)
{
	int	x;
	int	y;

	y = 0;
	while (*file)
	{
		x = 0;
		while (*file && *file != '\n')
		{
			if (is_valid(*file))
			{
				map->map[y][x] = *file - 48;
				if (++x == map->map_x)
					return (MAP);
			}
			file++;
		}
		if (++y == map->map_y || x != map->map_x - 1)
			return (MAP);
		file++;
	}
	return (y == map->map_y - 1 ? OK : MAP);
}

static t_error	check_map(int **map, int map_x, int map_y)
{
	int	x;
	int	y;
	int	start;

	start = 0;
	y = 0;
	while (y < map_y)
	{
		x = 0;
		while (x < map_x)
		{
			if ((y == 0 || y == map_y - 1) && map[y][x] != '1')
				return (MAP);
			if ((x == 0 || x == map_x - 1) && map[y][x] != '1')
				return (MAP);
			if (is_start(map[y][x]))
				start++;
		}
		y++;
	}
	return (start == 1 ? OK : MAP);
}

t_error			parse_map(t_map *map, const char *file)
{
	if (get_mapsize(map, file))
		return (MAP);
	if ((map->map = malloc_map(map->map_x, map->map_y)) == NULL)
		return (MAP);
	if (copy_map(map, file))
	{
		escape_free_map(map->map, map->map_y);
		return (MAP);
	}
	if (check_map(map->map, map->map_x, map->map_y))
	{
		escape_free_map(map->map, map->map_y);
		return (MAP);
	}
	return (OK);
}
