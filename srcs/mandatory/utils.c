/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:01:34 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 12:05:11 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	conditions(char *base)
{
	int	len_base;
	int	i;
	int	j;

	len_base = ft_strlen(base);
	i = 0;
	if (len_base == 0 || len_base == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	num_digit(long int nbr, int len_base)
{
	int	i;

	i = 0;
	while (nbr / len_base != 0)
	{
		i++;
		nbr /= len_base;
	}
	if (nbr % len_base)
		i++;
	return (i);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int			len_base;
	long int	nbr_long;
	char		*number;
	int			len_number;

	nbr_long = nbr;
	number = NULL;
	if (conditions(base) == 1)
	{
		len_base = ft_strlen(base);
		len_number = num_digit(nbr_long, len_base);
		number = ft_calloc(len_number + 1, sizeof(char));
		if (!number)
			return (NULL);
		while (nbr_long / len_base != 0)
		{
			len_number--;
			number[len_number] = base[nbr_long % len_base];
			nbr_long /= len_base;
		}
		number[0] = base[nbr_long % len_base];
	}
	return (number);
}

void	bit_received(int sig)
{
	(void)sig;
}
