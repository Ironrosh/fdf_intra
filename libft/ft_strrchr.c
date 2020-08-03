/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:14:18 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/10 17:24:10 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*tmp;

	tmp = (char*)s + ft_strlen((char*)s);
	while (*tmp != c)
	{
		if (tmp == s)
			return (NULL);
		tmp--;
	}
	return (tmp);
}
