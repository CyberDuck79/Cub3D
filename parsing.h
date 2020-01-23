/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 15:22:31 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/23 09:43:12 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "cub3d.h"

# define SPACES		" \t\r\n"
# define NUMBERS	"0123456789"
# define TOKENS		" RNOSWEAFC"
# define MAP_DEF	"102NSEW"
# define MIN_WINX	100
# define MAX_WINX	2560
# define MIN_WINY	100
# define MAX_WINY	1440

typedef struct	s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef enum	e_option
{
	ERROR,
	RES = 0b00000001,
	TEXT_NO = 0b00000010,
	TEXT_SO = 0b00000100,
	TEXT_WE = 0b00001000,
	TEXT_EA = 0b00010000,
	SPRITE = 0b00100000,
	FLOOR = 0b01000000,
	CEILING = 0b10000000,
	CONFIGURED = 0b11111111
}				t_option;

void			skip_set(const char **str, const char *set);
int				is_valid(char c, const char *set);
int				check_border(int pos, int end, int value);
int				parse_start(t_map *map, int x, int y);
t_error			parse_resolution(t_cub3d *cub, const char **file);
t_error			parse_textures(t_cub3d *cub, const char **file, t_option opt);
t_error			parse_colors(t_cub3d *cub, const char **file, t_option opt);
t_error			parse_map(t_map *map, const char *file);

#endif
