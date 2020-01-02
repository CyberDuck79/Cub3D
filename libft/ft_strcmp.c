/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 23:18:35 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/08 14:04:25 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	index = 0;
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	while (us1[index] && us2[index] && us1[index] == us2[index])
		index++;
	return (us1[index] - us2[index]);
}
