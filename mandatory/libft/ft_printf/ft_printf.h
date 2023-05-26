/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:16:59 by averdon           #+#    #+#             */
/*   Updated: 2022/11/01 17:02:02 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stdarg.h>
# include<unistd.h>
# include<stdlib.h>
# include"../libft.h"

int		ft_putstr(char *s);
int		ft_putchar(char c);
void	ft_put_unbr(unsigned long nbr, char *base, int *n);
void	ft_putnbr_hex(int nbr, char *base, int *n);
void	ft_putnbr_dec(int nbr, int *n);
int		ft_printf(const char *str, ...);
long	ft_iterative_power(int nb, int power);
void	ft_check_pointer(unsigned long nbr, char *base, int *n);

#endif
