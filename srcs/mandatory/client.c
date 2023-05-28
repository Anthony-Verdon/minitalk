/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:39:59 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 12:05:21 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int	main(int argc, char **argv)
{
	int	value_return;

	if (argc != 3)
	{
		ft_printf("invalid number of arguments\n");
		return (1);
	}
	else
	{
		signal(SIGUSR1, bit_received);
		value_return = send_pid(argv);
		if (value_return)
			return (1);
		value_return = send_message(argv);
		if (value_return)
			return (1);
	}
	return (0);
}
