/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:10:20 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/11 13:39:49 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	pt1 = (unsigned char*)dst;
	pt2 = (unsigned char*)src;
	i = 0;
	if (dst != src && n)
	{
		while (i < n)
		{
			pt1[i] = pt2[i];
			i++;
		}
	}
	return (dst);
}
