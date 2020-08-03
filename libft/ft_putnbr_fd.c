/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:16:33 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/07 18:19:11 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int test_num;

	test_num = n;
	if (test_num == -2147483648)
	{
		ft_putnbr_fd(-2147, fd);
		ft_putnbr_fd(483648, fd);
	}
	else
	{
		if (test_num < 0)
		{
			ft_putchar_fd('-', fd);
			test_num = test_num * (-1);
		}
		if (test_num > 9)
		{
			ft_putnbr_fd(test_num / 10, fd);
		}
		ft_putchar_fd('0' + (test_num % 10), fd);
	}
}
