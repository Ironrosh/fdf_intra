/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:44:42 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 18:54:43 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		size;

	if (s1 && s2)
	{
		size = ft_strlen((char*)s1) + ft_strlen((char*)s2);
		fresh = (char*)malloc(sizeof(char) * size + 1);
		if (fresh)
		{
			ft_strcpy(fresh, (char*)s1);
			ft_strcat(fresh, (char*)s2);
			return (fresh);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
