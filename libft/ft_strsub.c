/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:11:37 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 18:55:06 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	if (s)
	{
		i = 0;
		sub = (char*)malloc(sizeof(char) * len + 1);
		if (sub)
		{
			while (i < len)
			{
				sub[i] = s[i + start];
				i++;
			}
			sub[i] = '\0';
		}
		else
			return (NULL);
	}
	else
		return (NULL);
	return (sub);
}
