/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:40:43 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/13 16:10:40 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	count;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size != 0)
	{
		while (dst[i])
			i++;
		if (size > i)
			len += i;
		else
			len += size;
		count = 0;
		while (src[count] && i < (size - 1))
		{
			dst[i++] = src[count++];
		}
		dst[i] = '\0';
	}
	return (len);
}
