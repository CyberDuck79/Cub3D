/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 09:47:49 by flavien           #+#    #+#             */
/*   Updated: 2019/11/08 14:26:06 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (s[index])
	{
		if (s[index] != c)
		{
			count++;
			while (s[index] != c && s[index])
				index++;
		}
		else
			index++;
	}
	return (count);
}

static size_t	ft_size(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}

static size_t	ft_nextindex(char const *s, char c, size_t index)
{
	while (s[index] != c && s[index])
		index++;
	while (s[index] == c && s[index])
		index++;
	return (index);
}

char			**ft_split(char const *s, char c)
{
	size_t	size;
	size_t	str_i;
	size_t	tab_i;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_count(s, c);
	if (!(tab = (char**)ft_calloc(size + 1, sizeof(char*))))
		return (NULL);
	tab_i = 0;
	str_i = 0;
	while (s[str_i] == c && s[str_i])
		str_i++;
	while (tab_i < size)
	{
		tab[tab_i] = ft_substr(s, str_i, ft_size(s + str_i, c));
		str_i = ft_nextindex(s, c, str_i);
		tab_i++;
	}
	return (tab);
}
