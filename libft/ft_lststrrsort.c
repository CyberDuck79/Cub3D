/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststrrsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:15:19 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:15:49 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lststrrsort(t_list *lst)
{
	t_bool	sort;
	t_list	*head;
	void	*swp;

	if (!lst->next)
		return ;
	sort = true;
	head = lst;
	while (sort)
	{
		sort = false;
		while (lst)
		{
			while (lst->next && ft_strcmp(lst->content, lst->next->content) < 0)
			{
				sort = true;
				swp = lst->next->content;
				lst->next->content = lst->content;
				lst->content = swp;
			}
			lst = lst->next;
		}
		lst = head;
	}
}
