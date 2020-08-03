/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:14:37 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 17:44:53 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t count;

	count = 0;
	while (count < len && src[count])
	{
		dst[count] = src[count];
		count = count + 1;
	}
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
