/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:18:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/25 15:46:28 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			**escape_free_map(int **map, int index_stop)
{
	int index;

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
