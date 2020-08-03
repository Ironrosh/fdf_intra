/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:25:19 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/11 16:15:32 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ws(const char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && (str[i] == ' ' ||\
	str[i] == '\n' || str[i] == '\t'))
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		len;

	if (s)
	{
		start = ft_ws(s);
		end = ft_strlen((char*)s);
		while (start < end && (s[end - 1] == ' ' ||\
		s[end - 1] == '\n' || s[end - 1] == '\t'))
			end--;
		if (start == end)
			return (ft_strnew(1));
		len = end - start;
		return (ft_strsub(s, start, len));
	}
	else
		return (NULL);
}
