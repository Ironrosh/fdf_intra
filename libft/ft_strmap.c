/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:27:18 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/13 16:46:40 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (s && f)
	{
		fresh = ft_strnew(ft_strlen(s));
		if (fresh)
		{
			i = 0;
			while (s[i])
			{
				fresh[i] = f(s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
