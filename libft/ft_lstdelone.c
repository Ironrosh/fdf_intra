/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:55:52 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 16:06:47 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	**temp;

	if (alst && *alst && del)
	{
		temp = alst;
		del((*temp)->content, (*temp)->content_size);
		free(*temp);
		*temp = NULL;
	}
}
