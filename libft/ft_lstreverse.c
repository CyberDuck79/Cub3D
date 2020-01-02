/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstreverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:21:23 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:28:41 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstreverse(t_list **lst)
{
	t_list	*new;
	t_list	*end;
	int		index;

	new = ft_lstlast(*lst);
	index = ft_lstsize(*lst) - 1;
	while (index--)
	{
		end = ft_lstlast(*lst);
		end->next = ft_lstat(*lst, index);
		end->next->next = NULL;
	}
	*lst = new;
}
