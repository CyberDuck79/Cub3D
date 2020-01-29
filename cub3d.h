/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:17:32 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/29 19:54:39 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>

# include "libft/libft.h"
# include "minilibx/mlx.h"

# ifndef BONUS
#  define BONUS 0
# endif

typedef enum	e_error
{
	OK,
	ARGUMENT,
	OPEN_FILE,
	EXTENSION,
	SYNTAX,
	RESOLUTION,
	TEXTURES,
	COLORS,
	MAP
}				t_error;

#endif
