/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 13:45:34 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:20:48 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrchri(const char *s, int c)
{
	size_t	index;
	int		last;

	index = 0;
	last = -1;
	while (s[index])
	{
		if (s[index] == c)
			last = (int)index;
		index++;
	}
	if (!c)
		return (index);
	return (last);
}
