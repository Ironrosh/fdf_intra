/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 12:33:03 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/07 17:55:07 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	int test_num;

	test_num = nb;
	if (test_num == -2147483648)
	{
		ft_putnbr(-2147);
		ft_putnbr(483648);
	}
	else
	{
		if (test_num < 0)
		{
			ft_putchar('-');
			test_num = test_num * (-1);
		}
		if (test_num > 9)
		{
			ft_putnbr(test_num / 10);
		}
		ft_putchar('0' + (test_num % 10));
	}
}
