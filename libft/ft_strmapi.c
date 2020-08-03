/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:50:44 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/13 16:51:41 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				fresh[i] = f(i, s[i]);
				i++;
			}
			fresh[i] = '\0';
			return (fresh);
		}
	}
	return (NULL);
}
