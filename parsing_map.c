/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:15:07 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/28 13:16:14 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static t_error	get_mapsize(t_map *map, const char *file)
{
	while (*file != '\n')
	{
		if (is_valid(*file, MAP_DEF))
			map->x++;
		else if (*file == '2')
			map->sprites_nb++;
		else if (*file != ' ')
			return (MAP);
		file++;
	}
	while (*file)
	{
		if (!is_valid(*file, MAP_DEF) && *file != ' ' && *file != '\n')
			return (MAP);
		else if (*file == '2')
			map->sprites_nb++;
		else if (*file == '\n')
			map->y++;
		file++;
	}
	return (OK);
}

static t_error		malloc_map(t_map *map)
{
	int		index;

	index = 0;
	if ((map->map = (int**)malloc(sizeof(int*) * map->y)) == NULL)
		return (MAP);
	while (index < map->y)
	{
		if ((map->map[index] = (int*)malloc(sizeof(int) * map->x)) == NULL)
		{
			escape_free_map(map->map, index);
			return (MAP);
		}
		index++;
	}
	if ((map->sprites = malloc(map->sprites_nb * sizeof(t_sprite))) == NULL)
	{
		escape_free_map(map->map, index);
		return (MAP);
	}
	return (OK);
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
			if (is_valid(*file, MAP_DEF))
			{
				map->map[y][x] = *file - 48;
				if (++x > map->x)
					return (MAP);
			}
			file++;
		}
		if (++y > map->y || x != map->x)
			return (MAP);
		file++;
	}
	return (y == map->y ? OK : MAP);
}

static t_error	check_map(t_map *map)
{
	int	x;
	int	y;
	int	start;

	start = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if ((y == 0 || y == map->y) && map->map[y][x] < 1)
				return (MAP);
			if ((x == 0 || x == map->x) && map->map[y][x] < 1)
				return (MAP);
			if (parse_start(map, x, y))
				start++;
			x++;
		}
		y++;
	}
	return (start == 1 ? OK : MAP);
}

static void		get_sprites(t_map *map)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 2)
			{
				map->sprites[index].x = x + 0.5;
				map->sprites[index].y = y + 0.5;
				index++;
			}
			x++;
		}
		y++;
	}
}

t_error			parse_map(t_map *map, const char *file)
{
	if (get_mapsize(map, file))
		return (MAP);
	if (malloc_map(map))
		return (MAP);
	if (copy_map(map, file))
	{
		escape_free_map(map->map, map->y);
		return (MAP);
	}
	if (check_map(map))
	{
		escape_free_map(map->map, map->y);
		return (MAP);
	}
	get_sprites(map);
	return (OK);
}
