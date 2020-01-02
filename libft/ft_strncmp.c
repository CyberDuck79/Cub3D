/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:57:26 by flavien           #+#    #+#             */
/*   Updated: 2019/11/12 14:39:12 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t			index;
	unsigned char	*us1;
	unsigned char	*us2;

	index = 0;
	if (!len)
		return (0);
	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	len--;
	while (us1[index] && us2[index] && us1[index] == us2[index] && index < len)
		index++;
	return (us1[index] - us2[index]);
}
