/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 18:27:58 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/10 14:08:04 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (n != 0)
	{
		while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < (n - 1))
		{
			i++;
		}
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	else
		return (0);
}
