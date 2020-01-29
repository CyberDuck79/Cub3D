/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 09:26:00 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 19:55:02 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# include "data_structs.h"

typedef struct	s_draw
{
	int			y;
	int			y_end;
	int			x;
	int			x_end;
}				t_draw;

void	sprite_casting(t_map *map, t_cam *cam);
void	draw_sprites(t_cub3d *cub, t_cam *cam, t_sprite *arr, int size);

#endif
