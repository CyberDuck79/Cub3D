/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:18:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/31 09:51:57 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			**escape_free_map(int **map, int index_stop)
{
	int		index;

	index = 0;
	while (index < index_stop)
	{
		free(map[index]);
		index++;
	}
	free(map);
	return (NULL);
}

void		print_fps(t_cub3d *cub)
{
	double	frame_time;

	cub->old_time = cub->time;
	cub->time = clock();
	frame_time = (cub->time - cub->old_time) / 10000.0;
	system("clear");
	printf("%f\n", 60.0 / frame_time);
}

void		sort_sprites(t_sprite *sprites, int sprites_nb)
{
	int			i;
	int			sorted;
	t_sprite	tmp;

	sorted = 1;
	while (sorted)
	{
		i = 0;
		sorted = 0;
		while (i < sprites_nb - 1)
		{
			if (sprites[i].dist < sprites[i + 1].dist)
			{
				tmp = sprites[i];
				sprites[i] = sprites[i + 1];
				sprites[i + 1] = tmp;
				sorted++;
			}
			i++;
		}
	}
}

int			apply_fog(double dist, int texel)
{
	int rgb[4];

	rgb[0] = texel & 0xFF;
	rgb[1] = (texel >> 8) & 0xFF;
	rgb[2] = (texel >> 16) & 0xFF;
	rgb[3] = (texel >> 24) & 0xFF;
	rgb[0] -= (int)dist + 8;
	if (rgb[0] < 0x10)
		rgb[0] = 0x10;
	rgb[1] -= (int)dist + 8;
	if (rgb[1] < 0x10)
		rgb[1] = 0x10;
	rgb[2] -= (int)dist + 8;
	if (rgb[2] < 0x10)
		rgb[2] = 0x10;
	return (rgb[0] | rgb[1] << 8 | rgb[2] << 16 | rgb[3] << 24);
}
