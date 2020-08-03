/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:57:40 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/11 14:02:02 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	if (s1 && s2)
	{
		pt1 = (unsigned char*)s1;
		pt2 = (unsigned char*)s2;
		i = 0;
		while ((*pt1 || *pt2) && i < n)
		{
			if (*pt1 != *pt2)
				return (0);
			pt1++;
			pt2++;
			i++;
		}
	}
	return (1);
}
