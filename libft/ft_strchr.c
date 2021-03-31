/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:28:47 by rprieto-          #+#    #+#             */
/*   Updated: 2021/03/30 21:39:13 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*string;

	i = 0;
	string = (char *)s;
	while (string[i])
	{
		if (string[i] == c)
			return (&string[i]);
		i++;
	}
	if (c == '\0')
		return (&string[i]);
	return (NULL);
}
