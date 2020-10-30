/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_precision_width_handler.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:48:39 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/29 11:49:52 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*precision_special_case(char *string)
{
	char c;

	c = string[0];
	free(string);
	if (c == '+')
		return (ft_strdup("+"));
	if (c == ' ')
		return (ft_strdup(" "));
	else
		return (ft_strdup(""));
}

char	*handle_precision_neg(char *str, int precision, int str_lenght)
{
	char *precision_str;

	if (!(precision_str = malloc(precision + 1 + 1)))
		return (0);
	precision_str[0] = '-';
	ft_memset(precision_str + 1, '0', precision - str_lenght + 1);
	ft_strlcpy(precision_str + 1 +
	(precision - str_lenght + 1), str + 1, str_lenght);
	free(str);
	return (precision_str);
}

char	*handle_precision(char *str, char current_type, int precision)
{
	int		str_lenght;
	char	*precision_str;

	str_lenght = ft_strlen(str);
	if (current_type == 's')
		return (handle_precision_string(str, precision));
	if (str_lenght - 1 < precision && str[0] == '-')
		return (handle_precision_neg(str, precision, str_lenght));
	else if (precision > str_lenght)
	{
		if (!(precision_str = malloc(precision + 1)))
			return (0);
		ft_memset(precision_str, '0', precision - str_lenght);
		ft_strlcpy(precision_str + (precision - str_lenght),
		str, str_lenght + 1);
		free(str);
		return (precision_str);
	}
	else
		return (str);
}

char	*handle_precision_string(char *str, int precision)
{
	char	*precision_str;

	if (!(precision_str = malloc(precision + 1)))
		return (0);
	ft_strlcpy(precision_str, str, precision + 1);
	free(str);
	return (precision_str);
}

char	*handle_width_left(char *str, int width)
{
	int		str_length;
	char	*string;

	str_length = ft_strlen(str);
	if (str_length < width)
	{
		if (!(string = ft_calloc(width + 1, sizeof(char))))
			return (0);
		ft_memset(string, ' ', width - str_length);
		ft_strlcpy(string + (width - str_length), str, str_length + 1);
		free(str);
		return (string);
	}
	else
		return (str);
}
