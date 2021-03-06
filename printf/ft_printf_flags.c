/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiglesia <aiglesia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 13:41:38 by user42            #+#    #+#             */
/*   Updated: 2020/10/23 18:11:41 by aiglesia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_flag_value(const char **s, va_list ap)
{
	int i;

	*s = *s + 1;
	if (**s == '*')
	{
		i = va_arg(ap, int);
	}
	else
		i = ft_atoi(*s);
	return (i);
}

void	get_flags(const char **s, va_list ap, t_printf_list *flags)
{
	ft_memset(flags, 0, sizeof(t_printf_list));
	while (ft_findchr("-.0+# *123456789", **s) || ft_isdigit(**s))
	{
		if (**s == '#' || **s == '+' || (**s == ' ' && !flags->append))
		{
			flags->append = **s;
			*s = *s + 1;
		}
		else if (ft_findchr("-.0", **s))
			get_special_flags(s, flags, ap);
		else
		{
			if (**s == '*')
				flags->width = va_arg(ap, int);
			else
				flags->width = ft_atoi(*s);
			while (**s == '*' || ft_isdigit(**s) || ft_isspace(**s))
				*s = *s + 1;
		}
	}
}

void	get_special_flags(const char **s, t_printf_list *flags, va_list ap)
{
	if (**s == LEFT_MARGIN && !flags->width)
		flags->zeroes = set_flag_value(s, ap);
	if (**s == PRECISION && (flags->precision = true))
		flags->precision_value = set_flag_value(s, ap);
	if (**s == RIGHT_MARGIN)
		if ((flags->width = set_flag_value(s, ap)) && flags->width > 0)
			flags->width *= -1;
	while (**s == '*' || ft_isdigit(**s))
		*s = *s + 1;
	if (flags->zeroes < 0)
		flags->width = flags->zeroes;
	if (flags->precision_value < 0)
		flags->precision = false;
}

char	*handle_flags(char *str, t_printf_list *flags, char current_type)
{
	if (!(current_type == 'c'))
	{
		if (flags->precision)
		{
			if (!flags->precision_value && (current_type == 's' ||
			((hextoi(str) == 0) && current_type != 'p')))
				str = precision_special_case(str);
			else if (flags->precision_value)
				str = handle_precision(str,
				current_type, flags->precision_value);
			str = handle_appends(str, flags, current_type);
		}
		else
			str = handle_appends(str, flags, current_type);
		if (flags->width > 0)
			str = handle_width_left(str, flags->width);
		if (flags->width < 0)
			str = handle_width_right(str, -flags->width);
		else if (flags->zeroes > 0)
			str = handle_width_zeroes(str, flags, current_type);
	}
	return (str);
}
