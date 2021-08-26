/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboy <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 10:15:31 by mboy              #+#    #+#             */
/*   Updated: 2021/08/26 10:18:19 by mboy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/minitalk.h"

int	ft_strlen(char *str)
{
	int		idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	ft_putstr(char *str)
{
	int	idx;

	idx = 0;
	if (str)
	{
		while (str[idx])
		{
			write(1, &str[idx], 1);
			idx++;
		}
	}
}

void	ft_putnbr(int nbr)
{
	char	c;

	if (nbr == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			ft_putnbr(nbr);
		}
		else if (nbr < 10)
		{
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
		else
		{
			ft_putnbr(nbr / 10);
			c = (nbr % 10) + 48;
			write(1, &c, 1);
		}
	}
}

int	ft_atoi(const char *str)
{
	long int	idx;
	long int	nbr;
	long int	neg;

	idx = 0;
	nbr = 0;
	neg = 1;
	while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n'
		|| str[idx] == '\v' || str[idx] == '\f' || str[idx] == '\r')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			neg = -1;
		idx++;
	}
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		nbr = nbr * 10 + (str[idx] - 48);
		idx++;
	}
	return (nbr * neg);
}
