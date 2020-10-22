/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion_handler.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 12:47:45 by aiglesia          #+#    #+#             */
/*   Updated: 2020/10/22 16:47:19 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_conversions(const char **s, va_list ap,
t_printf_list *flags, int *i)
{
	char *str;

	if (**s == 'n')
		return (handle_n(i, va_arg(ap, int *), flags));
	if (**s == 'c')
		str = handle_char(va_arg(ap, int));
	else if (**s == 's')
		str = handle_string(va_arg(ap, char *));
	else if (**s == 'p')
		str = handle_ptr(va_arg(ap, char *), flags->precision_value,
		flags->precision);
	else if (**s == 'i' || **s == 'd')
		str = ft_itoa(va_arg(ap, int));
	else if (**s == 'u')
		str = ft_itoa(va_arg(ap, unsigned));
	else if (**s == 'x' || **s == 'X')
		str = handle_hex(va_arg(ap, unsigned int), **s);
	else if (**s == '%')
		str = handle_char('%');
	else
		return (0);
	return (str);
}

char	*handle_n(int *i, int *j, t_printf_list *flags)
{
	*j = *i;
	ft_memset(flags, 0, sizeof(t_printf_list));
	return (ft_strdup(""));
}

char	*handle_char(int c)
{
	char *str;

	if (!(str = ft_calloc(2, sizeof(char))))
		return (0);
	str[0] = c;
	return (str);
}

char	*handle_string(char *s)
{
	if (s)
		return (ft_strdup(s));
	else
		return (ft_strdup("(null)"));
}

char	*handle_ptr(char *ptr, int precision, int prec_bool)
{
	char	*p;
	int		str_lenght;

	if (!ptr)
	{
		if (prec_bool && precision == 0)
			p = ft_strdup("");
		else
			p = ft_strdup("0");
	}
	else
		p = handle_hex((unsigned long int)ptr, 'x');
	str_lenght = ft_strlen(p);
	if (precision > str_lenght)
	{
		ptr = handle_precision(p, 'i', precision);
		p = ptr;
	}
	ptr = ft_strjoin("0x", p);
	free(p);
	return (ptr);
}
