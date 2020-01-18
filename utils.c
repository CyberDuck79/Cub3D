/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:18:49 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/18 17:47:14 by fhenrion         ###   ########.fr       */
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
