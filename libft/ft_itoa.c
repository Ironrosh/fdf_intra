/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:55:34 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/13 17:37:33 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_num_count(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int		ft_absolute(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

char			*ft_itoa(int n)
{
	size_t		size;
	char		*fresh;
	int			nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	size = ft_num_count(n);
	fresh = ft_strnew(size);
	if (fresh)
	{
		fresh[size + 1] = '\0';
		while (size-- && nb)
		{
			fresh[size] = ft_absolute(nb % 10) + '0';
			nb = nb / 10;
		}
		if (n < 0)
			fresh[0] = '-';
		return (fresh);
	}
	return (NULL);
}
