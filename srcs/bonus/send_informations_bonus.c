/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_informations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:18:11 by averdon           #+#    #+#             */
/*   Updated: 2022/11/27 11:16:08 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

void	send_pid_char(char *b_letter, int pid_server)
{
	int		y;
	int		len2;

	y = 0;
	len2 = ft_strlen(b_letter);
	while (y < 8 - len2)
	{
		usleep(50);
		kill(pid_server, SIGUSR1);
		y++;
	}
	while (y < 8)
	{
		usleep(50);
		if (b_letter[y - (8 - len2)] == '0')
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		y++;
	}
}

int	send_pid(char **argv)
{
	int		i;
	int		len;
	char	*b_letter;
	char	*pid_client;

	pid_client = ft_itoa(getpid());
	if (!pid_client)
		return (1);
	i = 0;
	len = ft_strlen(pid_client) + 1;
	while (i < len)
	{
		b_letter = ft_putnbr_base((unsigned char)pid_client[i], "01");
		if (!b_letter)
			return (1);
		usleep(50);
		send_pid_char(b_letter, ft_atoi(argv[1]));
		i++;
	}
	return (0);
}

void	send_message_char(char *b_letter, int pid_server)
{
	int		y;
	int		len2;

	y = 0;
	len2 = ft_strlen(b_letter);
	while (y < 8 - len2)
	{
		usleep(50);
		kill(pid_server, SIGUSR1);
		pause();
		y++;
	}
	while (y < 8)
	{
		usleep(50);
		if (b_letter[y - (8 - len2)] == '0')
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		pause();
		y++;
	}
}

int	send_message(char **argv)
{
	int		i;
	int		len;
	char	*b_letter;

	i = 0;
	len = ft_strlen(argv[2]) + 1;
	while (i < len)
	{
		b_letter = ft_putnbr_base((unsigned char)argv[2][i], "01");
		if (!b_letter)
			return (1);
		usleep(50);
		send_message_char(b_letter, ft_atoi(argv[1]));
		i++;
	}
	pause();
	return (0);
}
