/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 17:51:05 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 18:51:25 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*temp;

	temp = (t_list*)malloc(sizeof(t_list));
	if (!temp)
		return (NULL);
	if (content)
	{
		temp->content = (void*)malloc(content_size);
		if (!temp->content)
		{
			free(temp->content);
			return (NULL);
		}
		temp->next = NULL;
		temp->content = ft_memcpy(temp->content, content, content_size);
		temp->content_size = content_size;
	}
	else
	{
		temp->content = NULL;
		temp->next = NULL;
		temp->content_size = 0;
	}
	return (temp);
}
