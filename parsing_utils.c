/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:16:35 by fhenrion          #+#    #+#             */
/*   Updated: 2020/01/18 17:53:42 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	skip_set(const char **str, const char *set)
{
	const char	*index;

	index = set;
	while (*index)
	{
		if (**str == *index)
		{
			(*str)++;
			index = set;
		}
		else
			index++;
	}
}

int		is_valid(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W' \
	|| c == '0' || c == '1' || c == '2');
}

int		is_start(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}
