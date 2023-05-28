/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:41:45 by averdon           #+#    #+#             */
/*   Updated: 2022/11/26 12:05:29 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# include "libraries/libft/libft.h"
# include "signal.h"

char	*ft_putnbr_base(int number, char *base);
int		num_digit(long int nbr, int len_base);
int		send_message(char **argv);
int		send_pid(char **argv);
void	bit_received(int sig);

#endif
