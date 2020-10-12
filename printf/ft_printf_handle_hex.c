/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:49:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/04 13:12:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_hex(int nmb, char c)
{
	int		i;
	int		aux;
	char	str[get_hex_lenght(nmb)];
	char	temp[get_hex_lenght(nmb)];

	if (nmb == 0)
		return (ft_strdup("0"));
	if (nmb < 0)
		return (handle_hex_inverse(-nmb - 1, c));
	i = 0;
	while (nmb != 0)
	{
		aux = nmb % 16;
		nmb /= 16;
		str[i] = hex_c(aux, c);
		i++;
	}
	aux = i - 1;
	while (aux >= 0)
	{
		temp[i - aux - 1] = str[aux];
		aux--;
	}
	temp[i] = 0;
	return (ft_strdup(temp));
}

char	*handle_hex_inverse(int nmb, char c)
{
	char	str[9];
	int		i;
	int		aux;

	i = 7;
	ft_strlcpy(str, c == 'X' ? "FFFFFFFF" : "ffffffff", 9);
	while (nmb != 0)
	{
		aux = 15 - nmb % 16;
		if (aux != 16)
		{
			if (c == 'X')
				str[i] = (char)(aux > 9 ? aux - 10 + 'A' : aux + '0');
			else
				str[i] = (char)(aux > 9 ? aux - 10 + 'a' : aux + '0');
		}
		else
			str[i] = '0';
		nmb /= 16;
		i--;
	}
	return (ft_strdup(str));
}

char	*handle_hex_long(long int nmb, char c)
{
	int		i;
	int		aux;
	char	str[get_hex_lenght(nmb)];
	char	temp[get_hex_lenght(nmb)];

	if (nmb == 0)
		return (ft_strdup("0"));
	if (nmb < 0)
		return (handle_hex_inverse_long(-nmb - 1, c));
	i = 0;
	while (nmb != 0)
	{
		aux = nmb % 16;
		nmb /= 16;
		str[i] = hex_c(aux, c);
		i++;
	}
	aux = i - 1;
	while (aux >= 0)
	{
		temp[i - aux - 1] = str[aux];
		aux--;
	}
	temp[i] = 0;
	return (ft_strdup(temp));
}

char	*handle_hex_inverse_long(long int nmb, char c)
{
	char	str[17];
	int		i;
	int		aux;

	i = 15;
	str[16] = 0;
	ft_strlcpy(str, c == 'X' ? "FFFFFFFFFFFFFFFF" : "ffffffffffffffff", 9);
	while (nmb != 0)
	{
		aux = 15 - nmb % 16;
		if (aux != 16)
		{
			if (c == 'X')
				str[i] = (char)(aux > 9 ? aux - 10 + 'A' : aux + '0');
			else
				str[i] = (char)(aux > 9 ? aux - 10 + 'a' : aux + '0');
		}
		else
			str[i] = '0';
		nmb /= 16;
		i--;
	}
	return (ft_strdup(str));
}

int		get_hex_lenght(long int nmb)
{
	int i;

	if (nmb < 0)
		return (8);
	i = 0;
	while (nmb != 0)
	{
		i++;
		nmb /= 16;
	}
	return (i);
}
