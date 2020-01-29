/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:26:00 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 12:01:12 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "data_structs.h"

void			sprite_casting(t_map *map, t_cam *cam);
void			draw_sprites(t_cub3d *cub, t_cam *cam, t_sprite *arr, int size);

#endif
