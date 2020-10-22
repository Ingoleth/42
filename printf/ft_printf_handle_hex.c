/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:49:30 by user42            #+#    #+#             */
/*   Updated: 2020/10/21 11:59:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_hex_uppercase(unsigned long int nmb)
{
	int		i;
	int		aux;
	char	str[get_hex_lenght(nmb)];
	char	temp[get_hex_lenght(nmb)];

	i = 0;
	while (nmb != 0)
	{
		str[i] = nmb % 16;
		str[i] = str[i] > 9 ? str[i] - 10 + 'A' : str[i] + '0';
		nmb /= 16;
		i++;
	}
	str[i] = 0;
	aux = i - 1;
	while (aux >= 0)
	{
		temp[i - aux - 1] = str[aux];
		aux--;
	}
	temp[i] = 0;
	return (ft_strdup(temp));
}

char	*handle_hex(unsigned long int nmb, char c)
{
	int		i;
	int		aux;
	char	str[get_hex_lenght(nmb)];
	char	temp[get_hex_lenght(nmb)];

	if (nmb == 0 || c == 'X')
		return (nmb == 0 ? ft_strdup("0") : handle_hex_uppercase(nmb));
	i = 0;
	while (nmb != 0)
	{
		str[i] = nmb % 16;
		str[i] = str[i] > 9 ? str[i] - 10 + 'a' : str[i] + '0';
		nmb /= 16;
		i++;
	}
	str[i] = 0;
	aux = i - 1;
	while (aux >= 0)
	{
		temp[i - aux - 1] = str[aux];
		aux--;
	}
	temp[i] = 0;
	return (ft_strdup(temp));
}

int		get_hex_lenght(long int nmb)
{
	int i;

	i = 0;
	while (nmb != 0)
	{
		i++;
		nmb /= 16;
	}
	return (i);
}
