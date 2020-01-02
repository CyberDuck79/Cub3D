/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 18:10:34 by flavien           #+#    #+#             */
/*   Updated: 2019/10/26 10:12:25 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;
	size_t	index;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	index = 0;
	while (index < len)
	{
		str[index] = f(index, s[index]);
		index++;
	}
	return (str);
}
