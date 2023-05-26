/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:46:00 by averdon           #+#    #+#             */
/*   Updated: 2022/10/09 13:04:41 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	int		i;
	int		length;

	i = 0;
	length = size * nmemb;
	if (size != 0 && length / size != nmemb)
		return (NULL);
	array = malloc(length);
	if (!array)
		return (NULL);
	while (i < length)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
