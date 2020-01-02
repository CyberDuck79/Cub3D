/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:30:53 by fhenrion          #+#    #+#             */
/*   Updated: 2019/11/07 13:41:40 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		n = -nb;
		ft_putchar('-');
	}
	else
		n = nb;
	if (n < 10)
		ft_putchar((char)(n + '0'));
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
