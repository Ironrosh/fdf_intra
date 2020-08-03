/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:56:11 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/19 15:02:27 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	void		ft_free_content(void *content, size_t content_size)
{
	if (content)
		free(content);
	if (content_size)
		content_size = 0;
}

t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*temp;
	t_list		*fresh;

	if (lst && f)
	{
		if ((fresh = f(lst)))
		{
			temp = fresh;
			while (lst->next)
			{
				lst = lst->next;
				fresh->next = f(lst);
				if (!(fresh->next))
				{
					ft_lstdel(&temp, &ft_free_content);
					return (NULL);
				}
				fresh = fresh->next;
			}
			return (temp);
		}
	}
	return (NULL);
}
