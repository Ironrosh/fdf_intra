/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:38:19 by mhorpe            #+#    #+#             */
/*   Updated: 2019/09/15 18:53:51 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*memory;

	memory = (void*)malloc(sizeof(void) * size);
	if (memory)
	{
		ft_memset(memory, 0, size);
		return (memory);
	}
	else
		return (NULL);
}
