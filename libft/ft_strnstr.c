/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:11:52 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 17:53:30 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	size_t		count;

	i = 0;
	count = 0;
	if (to_find[0] == '\0')
	{
		return ((char*)str);
	}
	while (str[count] && count < len)
	{
		i = 0;
		while (to_find[i] == str[count + i] && count + i < len)
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
