/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:25:21 by averdon           #+#    #+#             */
/*   Updated: 2022/10/13 00:32:45 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new_string;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[start + i] && i < len)
		i++;
	new_string = malloc(i + 1);
	if (!new_string)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
