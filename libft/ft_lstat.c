/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:20:18 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 12:25:51 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstat(t_list *lst, size_t index)
{
	while (lst && index)
	{
		lst = lst->next;
		index--;
	}
	return (index ? NULL : lst);
}
