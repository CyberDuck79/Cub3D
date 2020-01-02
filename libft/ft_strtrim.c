/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:04:34 by flavien           #+#    #+#             */
/*   Updated: 2019/11/13 10:30:15 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char *set, const char c)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	len;

	if (!s1)
		return (NULL);
	else if (!set)
		return (ft_strdup(s1));
	index = 0;
	while (ft_isset((char*)set, s1[index]))
		index++;
	if (!s1[index])
		return (ft_strdup(""));
	len = ft_strlen(s1 + index) - 1;
	while (ft_isset((char*)set, s1[index + len]))
		len--;
	return (ft_substr(s1, index, len + 1));
}
