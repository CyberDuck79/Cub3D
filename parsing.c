/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:25:19 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/07 15:54:56 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

//faire une fonction de skip selon un set (a mettre en define)
static void	skip_set(char **map, char *set)
{
	//
}

t_error		get_resolution(t_cub3D *cub, char **map)
{
	skip_set(map, SPACES);
	if (**map != 'R')
		return (RESOLUTION);
	skip_set(map, SPACES);
	if ((cub->wx = ft_atoi(*map)) < MIN_WINX || cub->wx > MAX_WINX)
		return (RESOLUTION);
	skip_set(map, NUMBERS);
	skip_set(map, SPACES);
	if ((cub->wy = ft_atoi(*map)) < MIN_WINY || cub->wy > MAX_WINY)
		return (RESOLUTION);
	skip_set(map, NUMBERS);
	//
}