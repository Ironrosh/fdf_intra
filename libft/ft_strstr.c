/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:05:29 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 17:54:05 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t		i;
	int			count;

	i = 0;
	count = 0;
	if (to_find[0] == '\0')
	{
		return ((char*)str);
	}
	while (str[count])
	{
		i = 0;
		while (to_find[i] == str[count + i])
		{
			if ((i + 1) == ft_strlen(to_find))
			{
				return ((char*)str + count);
			}
			i = i + 1;
		}
		count = count + 1;
	}
	return (0);
}
