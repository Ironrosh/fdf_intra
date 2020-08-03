/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:02:07 by mhorpe            #+#    #+#             */
/*   Updated: 2020/07/30 22:44:38 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(const char *s, char c)
{
	int			i;
	int			words;

	words = 0;
	i = 0;
	if (s[i] != c && s[i])
	{
		i++;
		words++;
	}
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
			if (s[i] != c && s[i])
				words++;
		}
		i++;
	}
	return (words);
}
