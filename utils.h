/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:13:18 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 19:49:16 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "data_structs.h"

int		**escape_free_map(int **map, int index_stop);
void	print_fps(t_cub3d *cub);
void	sort_sprites(t_sprite *sprites, int sprites_nb);
int		apply_fog(double dist, int texel);
t_error	save_bmp(t_cub3d *cub);
int		close_game(t_cub3d *cub);

#endif
