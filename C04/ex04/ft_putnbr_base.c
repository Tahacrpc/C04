/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcirpici <tcirpici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 18:51:46 by tcirpici          #+#    #+#             */
/*   Updated: 2024/09/03 02:50:12 by tcirpici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_base_control(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return(0);
	while (base[i])
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return(0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-' || base[i] == '%' || base[i] == '/'
			|| base[i] == '*' || base[i] == '=' || base[i] == ','
			|| base[i] == '.' || base[i] < 33 || base[i] > 126)
			return(0);
		else
			i++;
	}
	return(1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	unsigned int	base_size;
	

	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	if (ft_base_control(base) == 1)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		i = (unsigned int)nbr;
		if (i >= base_size)
		{
			ft_putnbr_base(i / base_size, base);
			ft_putchar(base[i % base_size]);
		}
		if(i < base_size)	
			ft_putchar(base[i]);
	}
}
