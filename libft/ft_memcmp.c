/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:16:24 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/10 15:45:21 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	i = 0;
	if (n == 0)
		return (0);
	pt1 = (unsigned char*)s1;
	pt2 = (unsigned char*)s2;
	while (*pt1 == *pt2 && ++i < n)
	{
		pt1++;
		pt2++;
	}
	return ((int)(*pt1 - *pt2));
}
