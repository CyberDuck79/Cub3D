/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:22:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/07 15:54:51 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3D.h"

# define SPACES		" \t\r\n"
# define NUMBERS	"0123456789"
# define MIN_WINX	100
# define MAX_WINX	2560
# define MIN_WINY	100
# define MAX_WINY	1440

t_error	get_resolution(t_cub3D *cub, char **map);
t_error	get_textures(t_cub3D *cub, char **map);
t_error	get_colors(t_cub3D *cub, char **map);
t_error	get_map(t_cub3D *cub, char **map);

# endif