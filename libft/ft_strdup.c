/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 11:45:41 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 17:45:19 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		size;

	i = 0;
	while (s[i])
		i = i + 1;
	size = i;
	str = (char*)malloc(sizeof(*str) * (size + 1));
	i = 0;
	if (str)
	{
		while (i < size)
		{
			str[i] = s[i];
			i = i + 1;
		}
		str[i] = '\0';
	}
	return (str);
}
