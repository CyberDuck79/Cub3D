/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:19:36 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:28:33 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstmerge(t_list *lst1, t_list *lst2)
{
	if (!lst1 || !lst2)
		return ;
	while (lst1->next)
		lst1 = lst1->next;
	lst1->next = lst2;
}
