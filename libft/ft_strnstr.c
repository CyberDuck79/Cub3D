/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:17:18 by flavien           #+#    #+#             */
/*   Updated: 2019/10/26 15:47:55 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	str_i;
	size_t	sub_i;

	if (!sub[0])
		return ((char*)str);
	str_i = 0;
	while (str[str_i] && str_i < len)
	{
		if (str[str_i] == *sub)
		{
			sub_i = 0;
			while (str[str_i + sub_i] == sub[sub_i] && str[str_i + sub_i] &&
			str_i + sub_i < len)
				sub_i++;
			if (!sub[sub_i])
				return ((char*)str + str_i);
		}
		str_i++;
	}
	return (NULL);
}
