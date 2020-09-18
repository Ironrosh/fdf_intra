/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 21:37:09 by mhorpe            #+#    #+#             */
/*   Updated: 2020/09/19 01:46:13 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		ft_csym(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static void			ft_str_del(char **str, size_t j)
{
	while (str)
	{
		free(str[j]);
		j--;
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s || !(str = malloc((sizeof(char *) * (ft_count_words(s, c) + 1)))))
		return (NULL);
	while ((size_t)j < ft_count_words(s, c))
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c)
		{
			if (!(str[j] = ft_strndup((char*)&s[i], ft_csym((char*)&s[i], c))))
			{
				ft_str_del(str, j);
				return (NULL);
			}
			j++;
			i += ft_csym((char*)&s[i], c);
		}
	}
	str[j] = NULL;
	return (str);
}
