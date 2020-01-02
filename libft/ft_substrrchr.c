/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrrchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 13:00:31 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:21:03 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substrrchr(const char *s, char c)
{
	size_t	index;
	size_t	len;
	char	*sub;

	if (!s)
		return (NULL);
	if ((index = ft_strrchri(s, c)) == -1)
		return (ft_strdup(s));
	len = ft_strlen(s + index + 1);
	if (!(sub = (char*)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(sub, s + index + 1, len);
	return (sub);
}
