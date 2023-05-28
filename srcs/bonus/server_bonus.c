/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:39:50 by averdon           #+#    #+#             */
/*   Updated: 2022/11/27 11:30:33 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk_bonus.h"

int	g_pid_client;

void	end_of_message(char **string)
{
	if (!g_pid_client)
	{
		g_pid_client = ft_atoi(*string);
		*string = NULL;
	}
	else
	{
		ft_printf("%s", *string);
		*string = NULL;
		usleep(50);
		kill(g_pid_client, SIGUSR2);
		g_pid_client = 0;
	}
}

void	add_to_string(char **string, char c)
{
	char	*new_c;
	char	*temp;

	new_c = ft_calloc(2, sizeof(char));
	if (!new_c)
		return ;
	new_c[0] = c;
	temp = ft_strjoin(*string, new_c);
	free(*string);
	free(new_c);
	*string = temp;
	if (c == '\0')
		end_of_message(string);
}

void	handler_message(int sig)
{
	static int				bits;
	static unsigned char	c;
	static char				*string;

	bits++;
	c = c << 1;
	if (sig == SIGUSR2)
		c++;
	if (g_pid_client)
	{
		usleep(50);
		kill(g_pid_client, SIGUSR1);
	}
	if (bits == 8)
	{
		bits = 0;
		add_to_string(&string, c);
		c = 0;
	}
}

int	main(void)
{
	pid_t		pid_server;

	pid_server = getpid();
	g_pid_client = 0;
	signal(SIGUSR1, handler_message);
	signal(SIGUSR2, handler_message);
	ft_printf("Server PID : %d\n", pid_server);
	while (1)
		pause();
	return (0);
}
