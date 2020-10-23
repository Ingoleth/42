/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_misc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 19:40:18 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 17:47:37 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_c(int i, char c)
{
	if (i > 9)
		return (i - 10 + (c == 'X' ? 'A' : 'a'));
	else
		return (i + '0');
}

int		hextoi(char *s)
{
	int		i;
	int		lenght;
	int		nmb;
	char	*t;

	i = 0;
	lenght = ft_strlen(s) - 1;
	nmb = 0;
	if (!(t = malloc(lenght + 2)))
		return (0);
	ft_strlcpy(t, s, lenght + 2);
	while (s[i])
	{
		if (t[i] >= 'a' && t[i] <= 'z')
			t[i] -= 32;
		nmb += (ft_isdigit(s[i]) ? t[i] - '0' : 10 + t[i] - 'A')
		* ft_power(16, lenght);
		i++;
		lenght--;
	}
	free(t);
	return (nmb);
}

int		ft_power(int root, int exponent)
{
	if (exponent <= 0)
		return (1);
	return (root * ft_power(root, exponent - 1));
}

int		ft_findchr(const char *s, int c)
{
	int		i;
	char	*string;

	i = 0;
	string = (char*)s;
	while (string[i])
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}
