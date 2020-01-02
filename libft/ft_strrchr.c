/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:09:09 by fhenrion          #+#    #+#             */
/*   Updated: 2019/10/26 10:12:36 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	int		last;

	index = 0;
	last = -1;
	while (s[index])
	{
		if (s[index] == c)
			last = index;
		index++;
	}
	if (!c)
		return ((char*)s + index);
	return (last != -1 ? (char*)s + last : NULL);
}
