/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 13:16:57 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/02 16:03:18 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgrfx.h"

t_vect2	*vect2_init(int x, int y)
{
	t_vect2	*vect2;

	if ((vect2 = malloc(sizeof(t_vect2))) == NULL)
		return (NULL);
	vect2->x = x;
	vect2->y = y;
	return (vect2);
}

t_vect3	*vect3_init(int x, int y, int z)
{
	t_vect3	*vect3;

	if ((vect3 = malloc(sizeof(t_vect3))) == NULL)
		return (NULL);
	vect3->x = x;
	vect3->y = y;
	vect3->z = z;
	return (vect3);
}
