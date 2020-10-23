/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:47:27 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/23 18:13:22 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format_string, ...)
{
	int				i;
	va_list			ap;
	t_printf_list	flags;
	char			*str;

	i = 0;
	va_start(ap, format_string);
	while ((format_string = print_str(format_string, &i)))
	{
		get_flags(&format_string, ap, &flags);
		if ((str = handle_conversions(&format_string, ap, &flags, &i))
		&& *format_string != 'c')
		{
			str = handle_flags(str, &flags, *format_string);
			i += print_final(str);
			format_string++;
		}
		else if (*format_string == 'c')
			i += print_char(&format_string, str, flags.width);
	}
	return (i);
}

char	*handle_appends(char *str, t_printf_list *flags, char current_type)
{
	char *final_string;

	if (ft_findchr("+ ", flags->append) &&
	ft_findchr("iud", current_type) && *str != '-')
	{
		if (flags->append == '+')
			final_string = ft_strjoin("+", str);
		else
			final_string = ft_strjoin(" ", str);
		free(str);
	}
	else if (flags->append && ft_findchr("xX", current_type) && hextoi(str))
	{
		if (current_type == 'x')
			final_string = ft_strjoin("0x", str);
		if (current_type == 'X')
			final_string = ft_strjoin("0X", str);
		free(str);
	}
	else
		final_string = str;
	return (final_string);
}

char	*zeroes_special_case(char *str, int zeroes, char current_type)
{
	int		lenght;
	char	*s;

	lenght = ft_strlen(str) - 1;
	if (!(s = malloc(zeroes + 1)))
		return (0);
	ft_strlcpy(s + zeroes - lenght, str + 2, lenght);
	free(str);
	ft_memset(s, '0', zeroes - lenght);
	return (current_type == 'x' ? ft_strjoin("0x", s) : ft_strjoin("0X", s));
}

char	*handle_width_zeroes(char *str, t_printf_list *flags,
char current_type)
{
	int		str_length;
	char	*aux;

	if (flags->precision)
		return (handle_width_left(str, flags->zeroes));
	str_length = ft_strlen(str);
	if (str_length < flags->zeroes)
	{
		if (current_type != 's'  && *str != '-'
		&& (flags->append == '+' || flags->append == ' '))
		{
			aux = malloc(flags->zeroes + 1);
			aux[0] = flags->append;
			ft_memset(aux + 1, '0', flags->zeroes - str_length);
			ft_strlcpy(&aux[flags->zeroes - str_length + 1],
			str + 1, str_length);
			free(str);
			return (aux);
		}
		if (flags->append == '#' && hextoi(str))
			return (zeroes_special_case(str, flags->zeroes - 1, current_type));
		return (handle_precision(str, 'i', *str == '-' ?
		flags->zeroes - 1 : flags->zeroes));
	}
	return (str);
}

char	*handle_width_right(char *str, int width)
{
	int		str_length;
	char	*temp;

	str_length = ft_strlen(str);
	if (width > str_length)
	{
		if (!(temp = ft_calloc(width + 1, sizeof(char))))
			return (0);
		ft_strlcpy(temp, str, str_length + 1);
		ft_memset(temp + str_length, ' ', width - str_length);
		free(str);
		return (temp);
	}
	else
		return (str);
}
