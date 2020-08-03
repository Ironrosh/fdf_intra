/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 10:38:15 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 17:44:20 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int count;

	count = 0;
	while (src[count] != '\0')
	{
		dst[count] = src[count];
		count = count + 1;
	}
	dst[count] = '\0';
	return (dst);
}
