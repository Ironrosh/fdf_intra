/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:08:05 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/10 15:14:35 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pt;

	pt = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (pt[i] == (unsigned char)c)
			return (pt + i);
		i++;
	}
	return (NULL);
}
