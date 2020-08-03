/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:47:38 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 16:53:11 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*temp;

	if (lst && f)
	{
		temp = lst;
		while (temp->next)
		{
			f(temp);
			temp = temp->next;
		}
		f(temp);
	}
}
