/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:18:36 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 16:21:11 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*temp1;
	t_list	*temp2;

	if (alst && *alst && del)
	{
		temp1 = *alst;
		while (temp1)
		{
			temp2 = temp1->next;
			del(temp1->content, temp1->content_size);
			free(temp1);
			temp1 = temp2;
		}
		*alst = NULL;
	}
}
