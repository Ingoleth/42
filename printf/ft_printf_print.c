/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 12:37:42 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 16:47:15 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_final(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (ft_printf("(null)"));
	while (str[i])
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	free(str);
	return (i);
}

int			print_char(const char **format_string, char *c, int width)
{
	int i;

	i = 1;
	while (width > 1)
	{
		ft_putchar_fd(' ', 1);
		width--;
		i++;
	}
	ft_putchar_fd(*c, 1);
	free(c);
	while (width < -1)
	{
		ft_putchar_fd(' ', 1);
		width++;
		i++;
	}
	*format_string = *format_string + 1;
	return (i);
}

const char	*print_str(const char *s, int *pi)
{
	int j;

	j = 0;
	while (s[j])
	{
		if (s[j] == '%')
			return (&s[j] + 1);
		write(1, &s[j], 1);
		*pi = *pi + 1;
		j++;
	}
	return (0);
}
