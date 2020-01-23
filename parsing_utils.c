/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:16:35 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 12:07:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

int		check_border(int pos, int end, int value)
{
	return ((pos == 0 || pos == end) && value != 1);
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