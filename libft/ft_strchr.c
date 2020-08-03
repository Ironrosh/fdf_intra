/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:59:37 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/10 17:12:02 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*tmp;

	tmp = (char*)s;
	while (*tmp != c)
	{
		if (!*tmp)
			return (NULL);
		tmp++;
	}
	return (tmp);
}
