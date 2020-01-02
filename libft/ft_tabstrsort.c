/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:28:52 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:21:30 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabstrsort(char **tab)
{
	t_bool	sort;
	char	**head;
	char	*swp;

	if (!tab || !*tab || !tab[1])
		return ;
	sort = true;
	head = tab;
	while (sort)
	{
		sort = false;
		while (*tab)
		{
			while (tab[1] && ft_strcmp(*tab, tab[1]) > 0)
			{
				sort = true;
				swp = tab[1];
				tab[1] = *tab;
				*tab = swp;
			}
			tab++;
		}
		tab = head;
	}
}
