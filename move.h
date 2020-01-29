/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 11:18:17 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 12:00:46 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "data_structs.h"

void			move_up(int **map, t_cam *cam);
void			move_down(int **map, t_cam *cam);
void			move_right(int **map, t_cam *cam);
void			move_left(int **map, t_cam *cam);

#endif
