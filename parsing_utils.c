/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:16:35 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 12:04:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

void	skip_set(const char **str, const char *set)
{
	const char	*index;

	index = set;
	while (*index)
	{
		if (**str == *index)
		{
			(*str)++;
			index = set;
		}
		else
			index++;
	}
}

int		is_valid(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int		parse_start(t_map *map, int x, int y)
{
	if (map->map[y][x] < 21)
		return (0);
	map->start_x = x;
	map->start_y = y;
	map->start_dir = (char)(map->map[y][x] + 48);
	map->map[y][x] = 0;
	return (1);
}

t_error	malloc_map(t_map *map)
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

t_error	copy_map(t_map *map, const char *file)
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
