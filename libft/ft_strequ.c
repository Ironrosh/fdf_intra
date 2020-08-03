/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:44:28 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/11 13:55:05 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char *pt1;
	unsigned char *pt2;

	if (s1 && s2)
	{
		pt1 = (unsigned char*)s1;
		pt2 = (unsigned char*)s2;
		while (*pt1 || *pt2)
		{
			if (*pt1 != *pt2)
				return (0);
			pt1++;
			pt2++;
		}
	}
	return (1);
}
