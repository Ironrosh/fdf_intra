/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:34:08 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/19 15:07:36 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = *alst;
	if (*alst && new && alst)
	{
		*alst = new;
		(*alst)->next = temp;
	}
	else if (new)
	{
		*alst = new;
		(*alst)->next = NULL;
	}
}
