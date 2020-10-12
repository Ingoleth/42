/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_libftfunctions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 19:39:39 by user42            #+#    #+#             */
/*   Updated: 2020/09/02 19:45:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "ft_printf.h"

int				ft_nbrlen(int n)
{
	long	nbr;
	int		len;

	len = 0;
	nbr = (n < 0) ? -n : n;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign *= (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number == 0)
			number = str[i] - 48;
		else
			number = number * 10 + str[i] - 48;
		i++;
	}
	return (number * sign);
}

static void		fill_nbr(char *string, unsigned int index, long int number)
{
	if (number >= 10 || number <= -10)
	{
		fill_nbr(string, index - 1, (number < 0 ? -number : number) / 10);
		string[index] = ((number < 0 ? -number : number) % 10) + 48;
	}
	else
		string[index] = (number >= 0 ? number : -number) + 48;
}

unsigned int	get_digits(long int n)
{
	unsigned int	digits;

	digits = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char			*ft_itoa(long int n)
{
	char			*string;
	long int		n_copy;
	unsigned int	digits;
	unsigned int	index;

	if (n == 0)
		return (ft_strdup("0"));
	digits = get_digits(n);
	n_copy = n;
	index = digits - 1;
	if (!(string = (char*)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	string[digits] = '\0';
	if (n_copy < 0)
		string[0] = '-';
	fill_nbr(string, index, n_copy);
	return (string);
}
