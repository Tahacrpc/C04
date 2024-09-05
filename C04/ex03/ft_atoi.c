/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 16:46:54 by tcirpici          #+#    #+#             */
/*   Updated: 2024/08/29 14:18:06 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	j;
	int	h;
	int	holder1;

	h = 0;
	j = 1;
	if (str[h] == '\0')
		return (0);
	while (str[h] == ' ' || str[h] == '\t' || str[h] == '\n' || str[h] == '\v'
		|| str[h] == '\f' || str[h] == '\r' || str[h] == '+')
		h++;
	while (str[h] == '-' || str[h] == '+')
	{
		if (str[h] == '-')
			j *= -1;
		h++;
	}
	holder1 = 0;
	while ((str[h] >= 48 && str[h] <= 57))
	{
		holder1 = holder1 * 10 + (str[h] - '0');
		h++;
	}
	return (holder1 * j);
}
