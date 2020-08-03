/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhorpe <mhorpe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 12:54:01 by mhorpe            #+#    #+#             */
/*   Updated: 2020/08/03 12:54:03 by mhorpe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_whitespaces(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || \
		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long int	result;
	int					negative;

	result = 0;
	negative = 0;
	i = ft_check_whitespaces(str);
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if ((result > 9223372036854775807 || i > 19) && !negative)
		return (-1);
	else if ((result > 9223372036854775807 || i > 19) && negative)
		return (0);
	if (negative)
		result *= -1;
	return ((int)result);
}
