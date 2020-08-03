/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:27:30 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/11 13:39:39 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,\
int c, size_t n)
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
			if (pt1[i] == (unsigned char)c)
				return ((void*)(dst + i + 1));
			i++;
		}
	}
	return (NULL);
}
